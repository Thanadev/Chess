#include "chesstabtest.h"

ChesstabTest::ChesstabTest()
{
    chesstab = new ChessTab();
}

ChesstabTest::~ChesstabTest()
{
    delete chesstab;
}

void ChesstabTest::runTests()
{
    qDebug() << "ChessTab tests";
    qDebug() << "    createChessTabTest";
    Q_ASSERT_X(createChessTabTest(), "createChessTab", "");
    qDebug() << "    populateChessTabTest";
    Q_ASSERT_X(populateChessTabTest(), "populateChessTab", "");
    qDebug() << "    selectEmptyCellTest";
    Q_ASSERT_X(selectEmptyCellTest(), "selectEmptyCellTest", "");
    qDebug() << "    selectOccupatedCellTest";
    Q_ASSERT_X(selectOccupatedCellTest(), "selectOccupatedCellTest", "");
    qDebug() << "    movePieceToEmptyValidLocationTest";
    Q_ASSERT_X(movePieceToEmptyValidLocationTest(), "movePieceToEmptyValidLocationTest", "");
}

bool ChesstabTest::createChessTabTest()
{
    bool isValid = true;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (chesstab->getCellAt(x, y) != NULL) {
                isValid &= true;
            }
        }
    }

    return isValid;
}

bool ChesstabTest::populateChessTabTest()
{
    bool isValid = true;

    // Check that the first and the last rows are filled
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if ((y < 2 || y >= 6) && chesstab->getCellAt(x, y) != NULL && chesstab->getCellAt(x, y)->getCurrentPiece() != NULL) {
                isValid &= true;
            } else if (chesstab->getCellAt(x, y) != NULL && chesstab->getCellAt(x, y)->getCurrentPiece() != NULL) {
                isValid &= false;
            }
        }
    }

    return isValid;
}

bool ChesstabTest::selectEmptyCellTest()
{
    bool isValid = false;

    // Try to select a cell at an arbitrary empty cell and check : its position, currentSelectedCell attribute
    chesstab->resetSelectedCell();
    ChessCell *cell = chesstab->selectCell(4,4);
    if (cell != NULL && cell->getCurrentPiece() == NULL && cell->getPosition() == Position(4,4) && chesstab->getCurrentSelectedCell() != NULL) {
        isValid = true;
    }

    return isValid;
}

bool ChesstabTest::selectOccupatedCellTest()
{
    bool isValid = false;

    // Try to select a cell at an arbitrary occupated cell and check : its position, currentSelectedCell attribute, occupant
    chesstab->resetSelectedCell();
    ChessCell *cell = chesstab->selectCell(5,1);
    if (cell != NULL && cell->getCurrentPiece() != NULL && cell->getPosition() == Position(5, 1) && chesstab->getCurrentSelectedCell() != NULL) {
        isValid = true;
    }

    return isValid;
}

bool ChesstabTest::movePieceToEmptyValidLocationTest()
{
    bool isValid = false;

    // Select an occupated cell and tell the new selected cell to get the piece
    chesstab->resetSelectedCell();
    ChessCell *originCell = chesstab->selectCell(1,1);
    ChessCell *destinationCell = chesstab->selectCell(1,2);

    // Check if the position of the piece have changed, if the two cells have exchanged content
    if (originCell != NULL && destinationCell != NULL &&
            originCell->getCurrentPiece() == NULL && destinationCell->getCurrentPiece() != NULL &&
            destinationCell->getCurrentPiece()->getPosition() == destinationCell->getPosition()) {
        isValid = true;
    }

    chesstab->resetTab();

    return isValid;
}
