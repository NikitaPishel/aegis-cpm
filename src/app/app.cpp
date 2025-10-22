#include "cpm/app.h"
#include "cpm/actionStore.h"
#include "cpm/bActions/quit.h"
#include "cpm/iokey.h"
#include "cpm/frame.h"
#include "graphics.h"

namespace cpm {
    class App::Impl {
    public:
        Impl() : frame(1.2) {}
    
        bool status = true;

        Frame frame;
        Graphics gHandler;
    };
    
    void App::shutdown() {
        this->pImpl->status = false;
    }

    App::App() : pImpl(std::make_unique<Impl>()) {}

    App::~App() {}

    void App::run() {
        // check if pImpl loaded
        if (!pImpl) return;
        
        // load actions store
        ActionStore& actions = ActionStore::getInstance();

        // link pointers between modules
        actions.linkApp(*this);
        pImpl->gHandler.linkFrame(&pImpl->frame);

        // start main loop
        while (pImpl->status) {
            actions.autoRunAction();

            pImpl->gHandler.handleImage();

            cpm::IoKey::getInstance().resetCapture();
        }
    }
}