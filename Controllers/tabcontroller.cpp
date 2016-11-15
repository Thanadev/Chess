#include "tabcontroller.h"

TabController::TabController()
{
    tabView = new TabView();
    model = new ChessTab();
    whitePlayerTurn = true;

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
    ChessCell* cell = model->getCellAt(pos);

    if (model->getCurrentSelectedCell() != NULL && model->getCurrentSelectedCell()->getCurrentPiece() != NULL) {
        if (model->selectCell(pos) != NULL) {
            qDebug() << "Cell selected";
            whitePlayerTurn = !whitePlayerTurn;
            model->resetSelectedCell();
        }
    } else if (cell != NULL && cell->getCurrentPiece() != NULL && cell->getCurrentPiece()->getIsWhite() == whitePlayerTurn) {
        model->selectCell(pos);
    }
}

TabView* TabController::getView()
{
    return tabView;
}
