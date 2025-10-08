#ifndef IOSTRUCT_MAIN_H
#define IOSTRUCT_MAIN_H

#include <fstream>
#include <stdexcept>
#include <memory>
#include <nlohmann/json.hpp>
#include "cpm/frame.h"

namespace cpm {
    class JsonFrame {
    private:
        Frame* framePtr;

        void write(const std::string& filename, const nlohmann::json& j) const;
        nlohmann::json read(const std::string& filename) const;
    
    public:
        JsonFrame();

        void linkFrame(Frame& frame);
    };
}

#endif