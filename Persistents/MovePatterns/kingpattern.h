#ifndef KINGPATTERN_H
#define KINGPATTERN_H

#include "basepattern.h"

class KingPattern : public BasePattern
{
public:
    KingPattern(bool headedUp);
    ~KingPattern();
    virtual bool checkPattern(Position start, Position end);
};

#endif // KINGPATTERN_H
