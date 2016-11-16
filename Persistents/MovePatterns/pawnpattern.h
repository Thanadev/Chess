#ifndef PAWNPATTERN_H
#define PAWNPATTERN_H

#include "basepattern.h"

class PawnPattern : public BasePattern
{
public:
    PawnPattern(bool headedUp);
    ~PawnPattern();
    virtual bool checkPattern(Position start, Position end, bool isOccupatedByEnemy);
};

#endif // PAWNPATTERN_H
