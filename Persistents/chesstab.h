#ifndef CHESSTAB_H
#define CHESSTAB_H

#include <QList>
#include <QDebug>
#include <QLabel>

#include "Pieces/pieceentity.h"
#include "Pieces/pawnentity.h"
#include "Pieces/kingentity.h"
#include "Pieces/knightentity.h"
#include "Pieces/bishopentity.h"
#include "Pieces/rookentity.h"
#include "Pieces/queenentity.h"
#include "chesscell.h"
#include "player.h"

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
    bool isSomeoneInWay (Position start, Position end, PieceEntity *except = NULL);
    void createTab();
    void populateTab();
    QList<PieceEntity *>* getPiecesOfColor(bool white) const;

protected:
    bool movePieceFromSelectedCell(ChessCell* destination);
    bool hasToCheckSomeoneInWay(PieceEntity *piece);
    bool canEatPiece(PieceEntity *piece);
    bool isKingCheck(bool isKingWhite);
    bool isKingCheck(bool isKingWhite, Position pos);
    bool isKingCheckmate(bool isKingWhite);
    bool checkKingMovement(PieceEntity *piece, Position pos);
    KingEntity* findKingOfColor(bool isKingWhite);

    static ChessTab *latestInstance;
    ChessCell *cells[64];
    ChessCell *selectedCell;
    Player *whitePlayer;
    Player *blackPlayer;
    QList<PieceEntity *> *removedPieces;
};

#endif // CHESSTAB_H
