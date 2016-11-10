#include "tabcontroller.h"

TabController::TabController()
{
    tabView = new TabView();
    model = new ChessTab();

    QObject::connect(tabView, SIGNAL(cellClickedWithPos(Position)), this, SLOT(cellSelectedHandler(Position)));

    tabView->instantiateTab(model);
}

TabController::~TabController()
{
    delete model;
    delete tabView;
}


void TabController::cellSelectedHandler(Position pos)
{
    model->selectCell(pos);
}

TabView* TabController::getView()
{
    return tabView;
}
