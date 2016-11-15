#include "cellview.h"

CellView::CellView(QWidget *parent) : QPushButton(parent)
{
    initCell();
}

CellView::CellView(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    initCell();
}

CellView::CellView(const QIcon &icon, const QString &text, QWidget *parent) : QPushButton(icon, text, parent)
{
    initCell();
}

CellView::~CellView()
{
    delete model;
}

void CellView::initCell()
{
    model = NULL;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(clickedHandler()));
}

ChessCell* CellView::getModel() const
{
    return model;
}

/**
 * @brief CellView::setModel
 * @param cell
 */
void CellView::setModel(ChessCell *cell)
{
    model = cell;

    updateView();
}

/**
 * @brief CellView::clickedHandler
 */
void CellView::clickedHandler()
{
    if (model != NULL) {
        emit clickedWithPosition(model->getPosition());
    }
}

void CellView::updateView()
{
    if (model->getCurrentPiece() != NULL) {
        this->setIcon(model->getCurrentPiece()->getIcon());
    } else {
        this->setIcon(QIcon());
    }
}
