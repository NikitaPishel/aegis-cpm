#ifndef ACTION_STORE_REG_H
#define ACTION_STORE_REG_H

#include <string>
#include <memory>
#include "cpm/action.h"

namespace cpm {
    struct ActionReg {
            ActionReg(const char& bind, Action* tool);
            ActionReg(const char& bind, std::unique_ptr<Action> tool);
    };
}

#endif