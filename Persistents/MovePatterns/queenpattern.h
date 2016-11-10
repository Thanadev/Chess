#ifndef QUEENPATTERN_H
#define QUEENPATTERN_H

#include "basepattern.h"

class QueenPattern : public BasePattern
{
public:
    QueenPattern(bool headedUp);
    ~QueenPattern();
    bool checkPattern(Position start, Position end);
};

#endif // QUEENPATTERN_H
