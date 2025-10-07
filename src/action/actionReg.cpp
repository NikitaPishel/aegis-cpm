#include <string>
#include <memory>
#include "cpm/actionReg.h"
#include "cpm/actionStore.h"
#include "cpm/action.h"

namespace cpm {
    ActionReg::ActionReg(const std::string& name, std::unique_ptr<Action> action) {
        ActionStore::getInstance().setAction(name, std::move(action));
    }

    ActionReg::ActionReg(const std::string& name, Action* action) {
        ActionStore::getInstance().setAction(name, action);
    }
}