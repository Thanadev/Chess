#include "mainview.h"
#include "Tests/chesstester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    ChessTester *tester = ChessTester::getInstance();

    tester->runTests();
    w.show();

    return a.exec();
}
