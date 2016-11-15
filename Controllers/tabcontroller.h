#ifndef TABCONTROLLER_H
#define TABCONTROLLER_H

#include <QObject>

#include "../Views/tabview.h"
#include "../Persistents/chesstab.h"

class TabController : public QObject
{
    Q_OBJECT
public:
    TabController();
    ~TabController();
    TabView* getView();
    void setWhitePlayerTurn();
private slots:
    void cellSelectedHandler(Position pos);
private:
    bool whitePlayerTurn;
    TabView *tabView;
    ChessTab *model;
};

#endif // TABCONTROLLER_H
