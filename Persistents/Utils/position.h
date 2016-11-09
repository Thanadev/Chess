#ifndef POSITION
#define POSITION

struct Position {
    int x, y;

    Position() {
        x = 0;
        y = 0;
    }

    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

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

