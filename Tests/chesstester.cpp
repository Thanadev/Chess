#include "chesstester.h"

ChessTester* ChessTester::instance = NULL;

ChessTester::ChessTester()
{
    tests = new QList<BaseTest *>();
    tests->append(new PawnTest());
    tests->append(new ChesstabTest());
    tests->append(new KingTest());
    tests->append(new BishopTest());
    tests->append(new KnightTest());
}

ChessTester::~ChessTester()
{
    tests->clear();
    delete tests;
    delete instance;
}

ChessTester* ChessTester::getInstance()
{
    if (instance == NULL) {
        instance = new ChessTester();
    }

    return instance;
}

/**
 * @brief ChessTester::runTests
 */
void ChessTester::runTests()
{
    for (int i = 0; i < tests->count(); i++) {
        tests->at(i)->runTests();
    }
}

void ChessTester::addTest(BaseTest *test)
{
    tests->append(test);
}

