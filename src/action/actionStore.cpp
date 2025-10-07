#include <unordered_map>
#include <stdexcept>
#include "cpm/actionStore.h"
#include "cpm/action.h"

namespace cpm {
    // Singleton getter
    ActionStore& ActionStore::getInstance() {
        static ActionStore store;
        return store;
    }

    // Actions store i/o
    void ActionStore::setAction(const std::string& name, Action* action) {
        this->actions[name] = std::unique_ptr<Action>(action);
    }

    void ActionStore::setAction(const std::string& name, std::unique_ptr<Action> action) {
        this->actions[name] = std::move(action);
    }

    void ActionStore::delAction(const std::string& name) {
        this->actions.erase(name);
    }

    std::unique_ptr<Action> ActionStore::getAction(const std::string& name) {
        auto it = this->actions.find(name);

        if (it == this->actions.end()) {
            throw std::runtime_error("Tool not found: " + name);
        }

        return it->second->clone();
    }
}