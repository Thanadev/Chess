#ifndef CHESSTAB_H
#define CHESSTAB_H

#include <QList>
#include <QDebug>
#include "Pieces/pieceentity.h"
#include "Pieces/pawnentity.h"
#include "Pieces/kingentity.h"
#include "Pieces/knightentity.h"
#include "Pieces/bishopentity.h"
#include "Pieces/rookentity.h"
#include "Pieces/queenentity.h"
#include "chesscell.h"

class ChessTab
{
public:
    ChessTab(bool createAndPopulate = true);
    ~ChessTab();
    ChessCell* getCellAt(int x, int y) const;
    ChessCell* getCellAt(Position pos) const;
    ChessCell* selectCell(Position cellPos);
    ChessCell* selectCell(int x, int y);
    ChessCell* getCurrentSelectedCell();
    ChessTab* getLatestInstance();
    void resetSelectedCell();
    void resetTab();
    QList<PieceEntity *>* getRemovedPieces();
    bool isSomeoneInWay (Position start, Position end);
    void createTab();
    void populateTab();

protected:
    void movePieceFromSelectedCell(ChessCell* destination);
    bool hasToCheckSomeoneInWay(PieceEntity *piece);

    static ChessTab *latestInstance;
    ChessCell *cells[64];
    ChessCell *selectedCell;
    QList<PieceEntity *> *removedPieces;
};

#endif // CHESSTAB_H
