#ifndef MATERIAL_STORE_H
#define MATERIAL_STORE_H

#include <string>
#include <unordered_map>
#include <memory>
#include "cpm/material.h"

namespace cpm {
    class MaterialStore {
    private:
        // global map of materials
        std::unordered_map<std::string, Material> materials;
        
    public:
        
        // Singleton instance method
        static MaterialStore& getInstance();
        
        // materials i/o
        void addMaterial(const std::string& name, Material material);
        Material& getMaterial(const std::string& name);

        static void registerMaterial(const std::string& bind, Material material);
    };
}
#endif