#include "cpm/bActions/quit.h"
#include "cpm/actionStore.h"
#include "cpm/actionReg.h"
#include "cpm/action.h"
#include "cpm/app.h"

namespace cpm {
    Quit::Quit() : Action() {}

    void Quit::run() {
        App& app = this->sPtr->getApp();

        app.shutdown();
    }

    std::unique_ptr<Action> Quit::clone() const {
        return std::make_unique<Quit>(*this);
    }

    static ActionReg quitReg('q', std::make_unique<Quit>());
}