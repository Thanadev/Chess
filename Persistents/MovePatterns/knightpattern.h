#ifndef KNIGHTPATTERN_H
#define KNIGHTPATTERN_H

#include "basepattern.h"

class KnightPattern : public BasePattern
{
public:
    KnightPattern(bool headedUp);
    ~KnightPattern();
    bool checkPattern(Position start, Position end);
};

#endif // KNIGHTPATTERN_H
