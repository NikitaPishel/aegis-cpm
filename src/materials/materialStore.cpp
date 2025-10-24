#include <unordered_map>
#include <stdexcept>
#include "cpm/materialStore.h"
#include "cpm/material.h"

namespace cpm {
    // Singleton getter
    MaterialStore& MaterialStore::getInstance() {
        static MaterialStore store;
        return store;
    }

    // Actions store i/o
    void MaterialStore::addMaterial(const std::string& name, Material material) {
        this->materials.emplace(name, std::move(material));
    }

    Material& MaterialStore::getMaterial(const std::string& name) {
        auto it = this->materials.find(name);

        if (it == this->materials.end()) {
            throw std::runtime_error("Material not found: " + name);
        }

        return it->second;
    }

    // static registerer of materials
    void MaterialStore::registerMaterial(const std::string& bind, Material material) {
        getInstance().addMaterial(bind, std::move(material));
    }
}