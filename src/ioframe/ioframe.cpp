#include "cpm/frame.h"
#include "cpm/ioframe.h"

namespace cpm {
    JsonFrame::JsonFrame() : framePtr(nullptr) {}
    
    void JsonFrame::write(const std::string& filename, const nlohmann::json& j) const {
        std::ofstream file(filename);
        if (!file.is_open()) throw std::runtime_error("Cannot open file for writing");
        file << j.dump(4);
    }

    nlohmann::json JsonFrame::read(const std::string& filename) const {
        std::ifstream file(filename);
        if (!file.is_open()) throw std::runtime_error("Cannot open file for reading");
        nlohmann::json j;
        file >> j;
        return j;
    }

    void JsonFrame::linkFrame(Frame& frame) {
        this->framePtr = &frame;
    }
}