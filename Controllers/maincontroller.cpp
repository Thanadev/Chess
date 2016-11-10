#include "maincontroller.h"

MainController::MainController()
{
    tabController = new TabController();
    mainView = new MainWindow();

    mainView->registerTabView(tabController->getView());
    mainView->show();
}

MainController::~MainController()
{
    delete tabController;
}

