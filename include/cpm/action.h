#ifndef ACTIONS_MAIN_H
#define ACTIONS_MAIN_H

#include <memory>

namespace cpm {
    class ActionStore;

    class Action {
    private:
        // Store pointer
        ActionStore* sPtr;

    public:
        explicit Action();
        virtual ~Action() = default;
        
        // virtual methods
        virtual void apply() = 0; 
        virtual std::unique_ptr<Action> clone() const = 0; 

        void setStore(ActionStore* iPtr);
    };
}

#endif