#include "pch.h"
#include "App.h"

int main() {

    App* app = new App();

    app->init();
    app->run();

    delete app;

    return 0;
}
