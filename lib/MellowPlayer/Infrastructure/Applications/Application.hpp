#pragma once

#include <MellowPlayer/UseCases.hpp>
#include "IApplication.hpp"
#include "../Services/HotkeysService.hpp"

BEGIN_MELLOWPLAYER_NAMESPACE(Infrastructure)

class Application : public IApplication {
public:
    Application(UseCases::IQtApplication& qtApp, UseCases::IMainWindow& mainWindow, HotkeysService& kotkeys);

    void initialize() override;
    int run() override;
    void restoreWindow() override;
    void quit() override;

private:
    UseCases::IQtApplication& qtApp;
    UseCases::IMainWindow& mainWindow;
    HotkeysService& kotkeys;
};

END_MELLOWPLAYER_NAMESPACE
