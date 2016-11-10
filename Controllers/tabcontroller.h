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
private slots:
    void cellSelectedHandler(Position pos);
private:
    TabView *tabView;
    ChessTab *model;
};

#endif // TABCONTROLLER_H
