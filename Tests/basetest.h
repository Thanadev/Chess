#ifndef BASETEST_H
#define BASETEST_H

#include <QtGlobal>
#include <QDebug>

class BaseTest
{
public:
    BaseTest();
    ~BaseTest();
    virtual void runTests() = 0;
};

#endif // BASETEST_H
