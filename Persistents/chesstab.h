#ifndef CHESSTAB_H
#define CHESSTAB_H

#include <QList>
#include "Pieces/pieceentity.h"
#include "Pieces/pawnentity.h"
#include "chesscell.h"

class ChessTab
{
public:
    ChessTab();
    ~ChessTab();
    ChessCell* getCellAt(int x, int y);
    ChessCell* getCellAt(Position pos);
    ChessCell* selectCell(Position cellPos);
    ChessCell* selectCell(int x, int y);
    ChessCell* getCurrentSelectedCell();
protected:
    void createTab();
    void populateTab();

    ChessCell *cells[64];
    ChessCell *selectedCell;
};

#endif // CHESSTAB_H
