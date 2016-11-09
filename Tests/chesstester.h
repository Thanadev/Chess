#ifndef CHESSTESTER_H
#define CHESSTESTER_H

#include <cstddef>
#include <QtGlobal>
#include <QLabel>
#include <QList>

#include "basetest.h"
#include "pawntest.h"
#include "chesstabtest.h"
#include "kingtest.h"

/**
 * @brief Main class executing the tests
 */
class ChessTester
{
public:
    ~ChessTester();
    static ChessTester* getInstance();
    void addTest(BaseTest *test);
    void runTests();
private:
    ChessTester();
    static ChessTester *instance;

    QList<BaseTest *> *tests;
};

#endif // CHESSTESTER_H
