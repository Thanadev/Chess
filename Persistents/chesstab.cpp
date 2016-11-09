#include "chesstab.h"

ChessTab::ChessTab()
{
    selectedCell = NULL;
    removedPieces = new QList<PieceEntity *>();

    createTab();
    populateTab();
}

ChessTab::~ChessTab()
{
    delete[] cells;
    delete removedPieces;
}

/**
 * @brief Instantiate the tab cells, giving position
 */
void ChessTab::createTab()
{
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            cells[y*8 + x] = new ChessCell(x, y);
        }
    }
}

/**
 * @brief Assign pieces to cells
 */
void ChessTab::populateTab()
{
    bool isWhite = true;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y < 2 || y >= 6) {

                isWhite = (y < 2);

                switch (x) {
                default:
                case 0:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 1:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 2:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 3:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 4:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 5:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 6:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                case 7:
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                    break;
                }
            }
        }
    }
}

/**
 * @brief ChessTab::selectCell
 * @param cellPos
 * @return
 */
ChessCell* ChessTab::selectCell(Position cellPos)
{
    selectedCell = selectCell(cellPos.x, cellPos.y);

    return selectedCell;
}

/**
 * @brief ChessTab::selectCell
 * @param x
 * @param y
 * @return
 */
ChessCell* ChessTab::selectCell(int x, int y)
{
    ChessCell* destination = getCellAt(x, y);
    movePieceFromSelectedCell(destination);

    selectedCell = destination;

    return selectedCell;
}

/**
 * @brief ChessTab::movePieceFromSelectedCell
 * @param destination
 */
void ChessTab::movePieceFromSelectedCell(ChessCell *destination)
{
    if (selectedCell != NULL && selectedCell->getCurrentPiece() != NULL) {
        if (selectedCell->getCurrentPiece()->move(destination->getPosition(), destination->getCurrentPiece())) {
            // Actualize cells piece
            if (destination->getCurrentPiece() != NULL && destination->getCurrentPiece()->getIsWhite() != selectedCell->getCurrentPiece()->getIsWhite()) {
                qDebug() << "Enemy killed";
                removedPieces->append(destination->getCurrentPiece());
            }

            destination->setPiece(selectedCell->getCurrentPiece());
            selectedCell->setPiece(NULL);
        }
    }
}

/**
 * @brief ChessTab::getCellAt
 * @param pos
 * @return
 */
ChessCell* ChessTab::getCellAt(Position pos)
{
    return getCellAt(pos.x, pos.y);
}

/**
 * @brief ChessTab::getCellAt
 * @param x
 * @param y
 * @return
 */
ChessCell* ChessTab::getCellAt(int x, int y)
{
    return cells[y*8 + x];
}

/**
 * @brief ChessTab::getCurrentSelectedCell
 * @return
 */
ChessCell* ChessTab::getCurrentSelectedCell()
{
    return selectedCell;
}

/**
 * @brief ChessTab::resetSelectedCell
 */
void ChessTab::resetSelectedCell()
{
    selectedCell = NULL;
}

/**
 * @brief ChessTab::resetTab
 */
void ChessTab::resetTab()
{
    for (int i = 0; i < 64; i++) {
        cells[i]->setPiece(NULL);
    }

    removedPieces->clear();

    populateTab();
}

QList<PieceEntity *>* ChessTab::getRemovedPieces()
{
    return removedPieces;
}
