#include "cpm/app.h"
#include "cpm/actionStore.h"
#include "cpm/bActions/quit.h"
#include "cpm/iokey.h"
#include "cpm/frame.h"
#include "cpm/ioframe.h"
#include "graphics.h"

namespace cpm {
    class App::Impl {
    public:
        Impl() : frame() {}

        void loadFrame(const std::string& path);
    
        bool status = true;

        Frame frame;
        Graphics gHandler;
    };

    void App::Impl::loadFrame(const std::string& path) {
        JsonFrame loader;

        loader.linkFrame(this->frame);
        loader.loadFrame(path);
    }
    
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

        // load frame
        pImpl->loadFrame("./data/conf/.test.json");

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