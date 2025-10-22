#include "cpm/ioframe.h"
#include "cpm/frame.h"
#include "cpm/materialStore.h"
#include "cpm/material.h"

namespace cpm {
    JsonFrame::JsonFrame() : framePtr(nullptr) {}
    
    void JsonFrame::write(const std::string& path, const nlohmann::json& j) const {
        std::ofstream file(path);
        if (!file.is_open()) throw std::runtime_error("Cannot open file for writing");
        file << j.dump(4);
    }

    nlohmann::json JsonFrame::read(const std::string& path) const {
        std::ifstream file(path);
        if (!file.is_open()) throw std::runtime_error("Cannot open file for reading");
        nlohmann::json j;
        file >> j;
        return j;
    }

    void JsonFrame::linkFrame(Frame& frame) {
        this->framePtr = &frame;
    }

    void JsonFrame::loadFrame(const std::string& path) {
        if (!framePtr) throw std::runtime_error("Frame not linked before loadFrame()");
        
        // read json
        nlohmann::json uformFrame = read(path);

        // load and add safety factor
        double safetyFactor = uformFrame.at("safetyFactor").get<double>();
        framePtr->setSafetyFactor(safetyFactor);

        // get joint and beam arrays
        nlohmann::json& joints = uformFrame.at("joints");
        nlohmann::json& beams = uformFrame.at("beams");

        // iterate through joints
        for (int i = 0; i < joints.size(); i++) {
            double xPos = joints[i].at("xPos").get<double>();
            double yPos = joints[i].at("yPos").get<double>();
            
            framePtr->addJoint(xPos, yPos);
        }

        // iterate through beams
        for (int i = 0; i < beams.size(); i++) {
            int originIndex = beams[i].at("originIndex").get<int>();
            double length = beams[i].at("length").get<double>();
            double width = beams[i].at("width").get<double>();
            double height = beams[i].at("height").get<double>();
            std::string materialName = beams[i].at("material").get<std::string>();

            Material material = MaterialStore::getInstance().getMaterial(materialName);
            
            
            framePtr->addBeam(originIndex, length, width, height, material);
        }
    }
}