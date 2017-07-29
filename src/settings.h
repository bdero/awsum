#pragma once

#include <string>
#include <yaml-cpp/yaml.h>

class Settings {
    std::string path;
    YAML::Node doc;

    void init(std::string path);

public:
    static const std::string SETTINGS_FILENAME;

    Settings();
    Settings(std::string path);
    void load();
    void save();
    YAML::Node get(bool reload = false);
};
