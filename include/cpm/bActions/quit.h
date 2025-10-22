#ifndef ACTION_BASE_QUIT
#define ACTION_BASE_QUIT

#include <memory>
#include "cpm/action.h"

namespace cpm {
    class Quit : public Action {
    public:
        explicit Quit();

        void run() override;
        std::unique_ptr<Action> clone() const override;
    };
}

#endif