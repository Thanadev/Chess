#include "chesstab.h"

ChessTab* ChessTab::latestInstance = NULL;

ChessTab::ChessTab(bool createAndPopulate)
{
    selectedCell = NULL;
    removedPieces = new QList<PieceEntity *>();
    blackPlayer = new Player(false);
    whitePlayer = new Player(true);
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
    delete blackPlayer;
    delete whitePlayer;
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
    PieceEntity *piece;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y < 2 || y >= 6) {

                isWhite = (y < 2);

                if (y == 0 || y == 7) {
                    switch (x) {
                    default:
                    case 0:
                        piece = new RookEntity(Position(x, y), isWhite);
                        break;
                    case 1:
                        piece = new KnightEntity(Position(x, y), isWhite);
                        break;
                    case 2:
                        piece = new BishopEntity(Position(x, y), isWhite);
                        break;
                    case 3:
                        piece = new KingEntity(Position(x, y), isWhite);
                        break;
                    case 4:
                        piece = new QueenEntity(Position(x, y), isWhite);
                        break;
                    case 5:
                        piece = new BishopEntity(Position(x, y), isWhite);
                        break;
                    case 6:
                         piece = new KnightEntity(Position(x, y), isWhite);
                        break;
                    case 7:
                        piece = new RookEntity(Position(x, y), isWhite);
                        break;
                    }
                } else {
                    piece = new PawnEntity(Position(x, y), isWhite);
                }

                if (isWhite) {
                    whitePlayer->addPiece(piece);
                } else {
                    blackPlayer->addPiece(piece);
                }

                cells[y*8+x]->setPiece(piece);
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

    if (selectedCell == NULL || movePieceFromSelectedCell(destination)) {
        selectedCell = destination;
    } else {
        selectedCell = NULL;
    }

    return selectedCell;
}

/**
 * @brief ChessTab::movePieceFromSelectedCell
 * @param destination
 */
bool ChessTab::movePieceFromSelectedCell(ChessCell *destination)
{
    bool validMovement = false;

    if (selectedCell != NULL && selectedCell->getCurrentPiece() != NULL) {

        if (checkKingMovement(selectedCell->getCurrentPiece(), destination->getPosition()) && selectedCell->getCurrentPiece()->move(destination->getPosition(), destination->getCurrentPiece())) {

            if (!isSomeoneInWay(selectedCell->getPosition(), destination->getPosition()) ||
                    !hasToCheckSomeoneInWay(selectedCell->getCurrentPiece())) {

                validMovement = true;

                // Check piece eating
                if (destination->getCurrentPiece() != NULL && destination->getCurrentPiece()->getIsWhite() != selectedCell->getCurrentPiece()->getIsWhite()) {

                    if (canEatPiece(destination->getCurrentPiece())) {
                        qDebug() << "Enemy killed";

                        if (destination->getCurrentPiece()->getIsWhite()) {
                            whitePlayer->removePiece(destination->getCurrentPiece());
                        } else {
                            blackPlayer->removePiece(destination->getCurrentPiece());
                        }

                        removedPieces->append(destination->getCurrentPiece());
                    } else {
                        validMovement = false;
                    }
                }
            } else {
                validMovement = false;
            }

            if (validMovement) {
                bool isKingWhite = !selectedCell->getCurrentPiece()->getIsWhite();
                bool isCheck = isKingCheck(!selectedCell->getCurrentPiece()->getIsWhite());

                if (isCheck && isKingCheckmate(!selectedCell->getCurrentPiece()->getIsWhite())) {
                    QString labelText = "";

                    if (isKingWhite) {
                        labelText = "The blacks wins !";
                    } else {
                        labelText = "The whites wins !";
                    }

                    QLabel *victoryLabel = new QLabel(labelText);
                    victoryLabel->show();
                }

                destination->setPiece(selectedCell->getCurrentPiece());
                selectedCell->setPiece(NULL);
            } else {
                 selectedCell->getCurrentPiece()->setPosition(selectedCell->getPosition());
            }
        }
    }

    return validMovement;
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
    ChessCell *cell = NULL;

    if (y < 8 && y >=0 && x < 8 && x >= 0) {
        cell = cells[y*8 + x];
    }

    return cell;
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

bool ChessTab::isSomeoneInWay(Position start, Position end, PieceEntity *except)
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

        if (x != end.x) {
            x += direction.x;
        }

        if (y != end.y) {
            y += direction.y;
        }

        if (getCellAt(x, y)->getCurrentPiece() != NULL && getCellAt(x, y)->getCurrentPiece() != except) {
            qDebug() << "Something is on the way : " + getCellAt(x, y)->getCurrentPiece()->getName();
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

QList<PieceEntity *>* ChessTab::getPiecesOfColor(bool white) const
{
    QList<PieceEntity *> *list;

    if (white) {
       list = whitePlayer->getPieces();
    } else {
        list = blackPlayer->getPieces();
    }

    return list;
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

bool ChessTab::canEatPiece(PieceEntity *piece)
{
    bool canEat = true;

    KingEntity* king = dynamic_cast<KingEntity *>(piece);

    if (king != NULL) {
        canEat = false;
    }

    return canEat;
}

KingEntity* ChessTab::findKingOfColor(bool isKingWhite)
{
    KingEntity *king = NULL;
    QList<PieceEntity *> *pieces;

    if (isKingWhite) {
        pieces = whitePlayer->getPieces();
    } else {
        pieces = blackPlayer->getPieces();
    }

    for (int i = 0; i < pieces->count(); i++) {
        king = dynamic_cast<KingEntity *>(pieces->at(i));

        if (king != NULL) {
            break;
        }
    }

    return king;
}

bool ChessTab::isKingCheck(bool isKingWhite)
{
    qDebug() << "checking check";
    bool isCheck = false;
    KingEntity *king = findKingOfColor(isKingWhite);

    if (king != NULL) {
        QList<PieceEntity *> *pieces = getPiecesOfColor(!isKingWhite);

        for (int i = 0; i < pieces->count(); i++) {
            Position originPos = pieces->at(i)->getPosition();

            if (pieces->at(i)->move(king->getPosition(), king) &&
                    (!isSomeoneInWay(originPos, king->getPosition(), pieces->at(i)) || !hasToCheckSomeoneInWay(selectedCell->getCurrentPiece()))) {
                qDebug() << "Check !";
                isCheck = true;
            }

            pieces->at(i)->setPosition(originPos);
        }
    } else {
        qDebug() << "ERROR : NO KING FOUND !";
    }

    return isCheck;
}

bool ChessTab::isKingCheck(bool isKingWhite, Position pos)
{
    qDebug() << "checking check";
    bool isCheck = false;

    QList<PieceEntity *> *pieces = getPiecesOfColor(!isKingWhite);

    for (int i = 0; i < pieces->count(); i++) {
        Position originPos = pieces->at(i)->getPosition();

        if (pieces->at(i)->move(pos, NULL) &&
                (!isSomeoneInWay(originPos, pos, pieces->at(i)) || !hasToCheckSomeoneInWay(selectedCell->getCurrentPiece()))) {
            qDebug() << "Check !";
            isCheck = true;
        }

        pieces->at(i)->setPosition(originPos);
    }

    return isCheck;
}

bool ChessTab::isKingCheckmate(bool isKingWhite)
{
    qDebug() << "checking checkmate";
    bool isCheckmate = true;
    KingEntity *king = findKingOfColor(isKingWhite);
    QList<ChessCell *> *toCheck = new QList<ChessCell *>();

    if (king != NULL) {
        QList<PieceEntity *> *pieces = getPiecesOfColor(!isKingWhite);

        int countY = -1;
        for (int y = king->getPosition().y - 1; y <= king->getPosition().y + 1; y++) {

            int countX = -1;
            for (int x = king->getPosition().x - 1; x <= king->getPosition().x + 1; x++) {

                ChessCell *cell = getCellAt(x, y);

                // Look only for the four cells surrounding the king
                if (cell != NULL && countX != countY && (countX + countY != 0)) {
                    toCheck->append(cell);

                    for (int i = 0; i < pieces->count(); i++) {
                        Position originPos = pieces->at(i)->getPosition();
                        bool notInWay = (!isSomeoneInWay(originPos, cell->getPosition(), pieces->at(i)) || !hasToCheckSomeoneInWay(selectedCell->getCurrentPiece()));
                        bool canMoveTo = pieces->at(i)->move(cell->getPosition(), cell->getCurrentPiece());

                        if (cell->getCurrentPiece() != NULL || (canMoveTo && notInWay)) {
                            isCheckmate = isCheckmate && true;
                            toCheck->removeOne(cell);
                        }

                        pieces->at(i)->setPosition(originPos);
                    }

                    if (toCheck->contains(cell)) {
                        qDebug() << QString::number(x) + " " + QString::number(y) + " is not taken";
                        isCheckmate = false;
                    }
                }

                countX++;
            }

            countY++;
        }
    } else {
        qDebug() << "ERROR : NO KING FOUND !";
    }

    if (isCheckmate) {
        qDebug() << "CHECKMATE !!!";
    }

    return isCheckmate;
}

bool ChessTab::checkKingMovement(PieceEntity *piece, Position pos)
{
    bool isValid = false;

    KingEntity *king = dynamic_cast<KingEntity *>(piece);

    if (king == NULL || (king != NULL && !isKingCheck(piece->getIsWhite(), pos))) {
        isValid = true;
    }

    return isValid;
}
