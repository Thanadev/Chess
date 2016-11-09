#include "basepattern.h"

BasePattern::BasePattern(bool headedUp)
{
    this->headedUp = headedUp;
}

BasePattern::~BasePattern()
{

}

int BasePattern::getDirection()
{
    int direction = 0;

    if (headedUp) {
        direction = 1;
    } else {
        direction = -1;
    }

    return direction;
}

bool BasePattern::checkPattern(Position start, Position end)
{
    qDebug() << "Base pattern called ! This message should NEVER appear.";
    return false;
}
