#include "chesstab.h"

ChessTab::ChessTab()
{
    createTab();
    populateTab();
}

ChessTab::~ChessTab()
{
    delete[] cells;
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
 * @brief Assign cells to
 */
void ChessTab::populateTab()
{
    Position pos;
    pos.x = 0;
    pos.y = 0;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y < 2 || y >= 6) {
                pos.x = x;
                pos.y = y;

                switch (x) {
                default:
                case 0:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 1:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 2:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 3:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 4:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 5:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 6:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                case 7:
                    cells[y*8+x]->setPiece(new PawnEntity(pos, true));
                    break;
                }
            }
        }
    }
}

ChessCell* ChessTab::selectCell(Position cellPos)
{
    selectedCell = getCellAt(cellPos);

    return selectedCell;
}

ChessCell* ChessTab::selectCell(int x, int y)
{
    selectedCell = getCellAt(x, y);

    return selectedCell;
}

ChessCell* ChessTab::getCellAt(Position pos)
{
    return cells[pos.y*8 + pos.x];
}

ChessCell* ChessTab::getCellAt(int x, int y)
{
    return cells[y*8 + x];
}

ChessCell* ChessTab::getCurrentSelectedCell()
{
    return selectedCell;
}
