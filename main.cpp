#include "Controllers/maincontroller.h"
#include "Tests/chesstester.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainController *mainController;
    ChessTester *tester = ChessTester::getInstance();

    tester->runTests();
    mainController = new MainController();

    return a.exec();
}
