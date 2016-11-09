#include "chesstabtest.h"

ChesstabTest::ChesstabTest()
{
    chesstab = new ChessTab();
}

ChesstabTest::~ChesstabTest()
{

}

void ChesstabTest::runTests()
{
    qDebug() << "ChessTab tests";
    Q_ASSERT_X(createChessTabTest(), "createChessTab", "");
    Q_ASSERT_X(populateChessTabTest(), "populateChessTab", "");
    Q_ASSERT_X(selectEmptyCellTest(), "selectEmptyCellTest", "");
    Q_ASSERT_X(selectOccupatedCellTest(), "selectOccupatedCellTest", "");
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
            if ((y < 2 || y >= 6) && chesstab->getCellAt(x, y)->getCurrentPiece() != NULL) {
                isValid &= true;
            } else if (chesstab->getCellAt(x, y)->getCurrentPiece() != NULL) {
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
    ChessCell *cell = chesstab->selectCell(4, 4);
    if (cell->getCurrentPiece() == NULL && cell->getPosition() == Position(4,4) && chesstab->getCurrentSelectedCell() != NULL) {
        isValid = true;
    }

    return isValid;
}

bool ChesstabTest::selectOccupatedCellTest()
{
    bool isValid = false;

    // Try to select a cell at an arbitrary occupated cell and check : its position, currentSelectedCell attribute, occupant
    ChessCell *cell = chesstab->selectCell(5, 1);
    qDebug() << (cell->getCurrentPiece() != NULL);
    if (cell->getCurrentPiece() != NULL && cell->getPosition() == Position(5, 1) && chesstab->getCurrentSelectedCell() != NULL) {
        isValid = true;
    }

    return isValid;
}
