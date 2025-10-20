#include <unordered_map>
#include <stdexcept>
#include "cpm/actionStore.h"
#include "cpm/action.h"
#include "cpm/iokey.h"

namespace cpm {
    // Singleton getter
    ActionStore& ActionStore::getInstance() {
        static ActionStore store;
        return store;
    }

    // Actions store i/o
    void ActionStore::setAction(const char& bind, Action* action) {
        this->actions[bind] = std::unique_ptr<Action>(action);
    }

    void ActionStore::setAction(const char& bind, std::unique_ptr<Action> action) {
        this->actions[bind] = std::move(action);
    }

    void ActionStore::delAction(const char& bind) {
        this->actions.erase(bind);
    }

    Action& ActionStore::getAction(const char& bind) {
        auto it = this->actions.find(bind);

        if (it == this->actions.end()) {
            throw std::runtime_error("Tool not found: " + bind);
        }

        return *it->second;
    }

    Action* ActionStore::getActionPtr(const char& bind) {
        auto it = this->actions.find(bind);

        if (it == this->actions.end()) {
            return nullptr;
        }

        return it->second.get();
    }

    void ActionStore::runAction(const char& bind) {
        this->getAction(bind).apply();
    }

    void ActionStore::autoRunAction() {
        IoKey& _ioKey = IoKey::getInstance();
        const char& key = _ioKey.getChar();
        
        Action* _action = this->getActionPtr(key);

        if (_action != nullptr) {
            _action->apply();
        }
    }
}