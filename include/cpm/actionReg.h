#ifndef ACTION_STORE_REG_H
#define ACTION_STORE_REG_H

#include <string>
#include <memory>
#include "cpm/action.h"

namespace cpm {
    struct ActionReg {
            ActionReg(const std::string& name, Action* tool);
            ActionReg(const std::string& name, std::unique_ptr<Action> tool);
    };
}

#endif