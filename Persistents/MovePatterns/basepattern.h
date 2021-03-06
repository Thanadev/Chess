#ifndef BASEPATTERN_H
#define BASEPATTERN_H

#include <QDebug>

#include "../Utils/position.h"

class BasePattern
{
public:
    BasePattern(bool headedUp);
    ~BasePattern();
    virtual bool checkPattern(Position start, Position end);
protected:
    int getDirection();
    bool headedUp;
};

#endif // BASEPATTERN_H
