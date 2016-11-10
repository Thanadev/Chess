#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "tabcontroller.h"
#include "../Views/mainwindow.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    MainController();
    ~MainController();
private:
    TabController *tabController;
    MainWindow *mainView;
};

#endif // MAINCONTROLLER_H
