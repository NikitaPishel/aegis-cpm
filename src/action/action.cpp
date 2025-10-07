#include <stdexcept>
#include "cpm/action.h"

namespace cpm {
    Action::Action() : sPtr(nullptr) {}
    
    void Action::setStore(ActionStore* sPtr) {
        this->sPtr = sPtr;
    }
}