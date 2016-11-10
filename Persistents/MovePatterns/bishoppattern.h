#ifndef BISHOPPATTERN_H
#define BISHOPPATTERN_H

#include "basepattern.h"

class BishopPattern : public BasePattern
{
public:
    BishopPattern(bool headedUp);
    ~BishopPattern();
    bool checkPattern(Position start, Position end);
};

#endif // BISHOPPATTERN_H
