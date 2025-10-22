#include "cpm/app.h"
#include "cpm/actionStore.h"
#include "cpm/bActions/quit.h"
#include "cpm/iokey.h"

namespace cpm {
    class App::Impl {
    public:
        Impl() {}
    
        bool status = true;
    };
    
    void App::shutdown() {
        this->pImpl->status = false;
    }

    App::App() : pImpl(std::make_unique<Impl>()) {}

    App::~App() {}

    void App::run() {
        if (!pImpl) return;
        
        ActionStore& actions = ActionStore::getInstance();

        actions.linkApp(*this);

        while (pImpl->status) {
            actions.autoRunAction();

            cpm::IoKey::getInstance().resetCapture();
        }
    }

}
