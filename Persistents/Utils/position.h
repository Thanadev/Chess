#ifndef POSITION
#define POSITION

struct Position {
    int x, y;

    inline bool operator == (Position other)
    {
        if (other.x == x && other.y == y) {
            return true;
        } else {
            return false;
        }
    }

    inline bool operator != (Position other)
    {
        if (other.x != x || other.y != y) {
            return true;
        } else {
            return false;
        }
    }
};


#endif // POSITION

