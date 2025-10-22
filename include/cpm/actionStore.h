#ifndef ACTIONS_STORE_H
#define ACTIONS_STORE_H

#include <unordered_map>
#include <memory>
#include "cpm/action.h"
#include "cpm/app.h"

namespace cpm {
    class ActionStore {
    private:
        // global map of actions
        std::unordered_map<char, std::unique_ptr<Action>> actions;
    
        Action& getAction(const char& bind);
        Action* getActionPtr(const char& bind);

        App* appPtr;

    public:
        ActionStore();
        ~ActionStore();
    
        // Singleton instance method
        static ActionStore& getInstance();

        // app linking method
        void linkApp(App& app);

        App& getApp();
        
        // Actions i/o
        void setAction(const char& bind, Action* action);
        void setAction(const char& bind, std::unique_ptr<Action> action);
        void delAction(const char& bind);

        void runAction(const char& bind);
        void autoRunAction();
    };
}
#endif