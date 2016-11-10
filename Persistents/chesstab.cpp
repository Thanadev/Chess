#include "chesstab.h"

ChessTab* ChessTab::latestInstance = NULL;

ChessTab::ChessTab(bool createAndPopulate)
{
    selectedCell = NULL;
    removedPieces = new QList<PieceEntity *>();
    latestInstance = this;

    if (createAndPopulate) {
        createTab();
        populateTab();
    }
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

                if (y == 0 || y == 7) {
                    switch (x) {
                    default:
                    case 0:
                        cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                        break;
                    case 1:
                        cells[y*8+x]->setPiece(new KnightEntity(Position(x, y), isWhite));
                        break;
                    case 2:
                        cells[y*8+x]->setPiece(new BishopEntity(Position(x, y), isWhite));
                        break;
                    case 3:
                        cells[y*8+x]->setPiece(new KingEntity(Position(x, y), isWhite));
                        break;
                    case 4:
                        cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                        break;
                    case 5:
                        cells[y*8+x]->setPiece(new BishopEntity(Position(x, y), isWhite));
                        break;
                    case 6:
                        cells[y*8+x]->setPiece(new KnightEntity(Position(x, y), isWhite));
                        break;
                    case 7:
                        cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
                        break;
                    }
                } else {
                    cells[y*8+x]->setPiece(new PawnEntity(Position(x, y), isWhite));
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

            if (!isSomeoneInWay(selectedCell->getPosition(), destination->getPosition()) ||
                    !hasToCheckSomeoneInWay(selectedCell->getCurrentPiece())) {
                // Actualize cells piece
                if (destination->getCurrentPiece() != NULL && destination->getCurrentPiece()->getIsWhite() != selectedCell->getCurrentPiece()->getIsWhite()) {
                    qDebug() << "Enemy killed";
                    removedPieces->append(destination->getCurrentPiece());
                }

                destination->setPiece(selectedCell->getCurrentPiece());
                selectedCell->setPiece(NULL);
            } else {
                selectedCell->getCurrentPiece()->setPosition(selectedCell->getPosition());
            }
        }
    }
}

/**
 * @brief ChessTab::getCellAt
 * @param pos
 * @return
 */
ChessCell* ChessTab::getCellAt(Position pos) const
{
    return getCellAt(pos.x, pos.y);
}

/**
 * @brief ChessTab::getCellAt
 * @param x
 * @param y
 * @return
 */
ChessCell* ChessTab::getCellAt(int x, int y) const
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

bool ChessTab::isSomeoneInWay(Position start, Position end)
{
    bool inWay = false;

    Position direction;
    if (end.x - start.x > 0) {
        direction.x = 1;
    } else {
        direction.x = -1;
    }

    if (end.y - start.y > 0) {
        direction.y = 1;
    } else {
        direction.y = -1;
    }

    int x = start.x, y = start.y;
    int secureCount = 0;

    while (secureCount < 500 && x != end.x - direction.x && y != end.y - direction.y) {
        secureCount++;
        x += direction.x;
        y += direction.y;

        if (getCellAt(x, y)->getCurrentPiece() != NULL) {
            inWay = true;
            break;
        } else if (secureCount > 498) {
            qDebug() << "SECURE COUNT IS EXPLODING, take care to the infinite loop";
            break;
        }
    }

    return inWay;
}

QList<PieceEntity *>* ChessTab::getRemovedPieces()
{
    return removedPieces;
}

ChessTab* ChessTab::getLatestInstance()
{
    return latestInstance;
}

bool ChessTab::hasToCheckSomeoneInWay(PieceEntity *piece)
{
    bool check = true;

    KnightEntity *knight = dynamic_cast<KnightEntity *>(piece);

    if (knight != NULL) {
        check = false;
    }

    return check;
}
