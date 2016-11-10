#ifndef ROOKPATTERN_H
#define ROOKPATTERN_H

#include "basepattern.h"

class RookPattern : public BasePattern
{
public:
    RookPattern(bool headedUp);
    ~RookPattern();
    bool checkPattern(Position start, Position end);
};

#endif // ROOKPATTERN_H
