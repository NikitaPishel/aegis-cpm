#include <string>
#include <memory>
#include "cpm/actionReg.h"
#include "cpm/actionStore.h"
#include "cpm/action.h"

namespace cpm {
    ActionReg::ActionReg(const char& bind, std::unique_ptr<Action> action) {
        ActionStore::getInstance().setAction(bind, std::move(action));
    }

    ActionReg::ActionReg(const char& bind, Action* action) {
        ActionStore::getInstance().setAction(bind, action);
    }
}