#ifndef APP_MAIN_H
#define APP_MAIN_H

#include <memory>

namespace cpm {
    class App {
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        App();
        ~App();

        void shutdown();
        void run();
    };
}

#endif