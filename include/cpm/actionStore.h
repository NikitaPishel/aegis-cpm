#ifndef ACTIONS_STORE_H
#define ACTIONS_STORE_H

#include <unordered_map>
#include <memory>
#include "cpm/action.h"

namespace cpm {
    class ActionStore {
    private:
        // global map of actions
        std::unordered_map<std::string, std::unique_ptr<Action>> actions;
    
    public:
        // Singleton instance method
        static ActionStore& getInstance();

        // Actions i/o
        std::unique_ptr<Action> getAction(const std::string& name);
        void setAction(const std::string& name, Action* action);
        void setAction(const std::string& name, std::unique_ptr<Action> action);
        void delAction(const std::string& name);
    };
}
#endif