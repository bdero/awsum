#include "settings.h"

#include <fstream>
#include <SDL2/SDL.h>

const std::string Settings::SETTINGS_FILENAME = "settings.yml";

Settings::Settings() {
    init("");
}

Settings::Settings(std::string path) {
    init(path);
}

void Settings::init(std::string path) {
    if (path.empty()) path = SDL_GetPrefPath("idunno", "Awsum");
    if (path.empty()) path = SDL_GetBasePath();
    path += Settings::SETTINGS_FILENAME;
    this->path = path;
    load();
}

void Settings::load() {
    try {
        doc = YAML::LoadFile(path);
    } catch (YAML::BadFile) {
        doc = YAML::Node();
        doc["window"]["width"] = 640;
        doc["window"]["height"] = 480;
        doc["window"]["fullscreen"] = false;
        save();
    }
}

void Settings::save() {
    std::ofstream out(path, std::ofstream::out);
    out << doc;
}

YAML::Node Settings::get(bool reload) {
    if (reload) load();
    return doc;
}
