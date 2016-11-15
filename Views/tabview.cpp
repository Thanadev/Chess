#include "tabview.h"

TabView::TabView(QWidget *parent) : QWidget(parent)
{
    cells = new QList<CellView *>();
    gridLayout = new QGridLayout();
    gridLayout->setSpacing(0);
}

TabView::~TabView()
{
    // Qt automatically destroy widgets on window closing

    for (int i = 0; i < cells->length(); i++) {
        delete cells->at(i);
    }
}

void TabView::cellClickedHandler(Position pos)
{
    emit cellClickedWithPos(pos);
    updateView();
}

void TabView::updateView()
{
    for (int i = 0; i < cells->length(); i++) {
        cells->at(i)->updateView();
    }
}

void TabView::instantiateTab(const ChessTab *tab)
{
    qDebug() << "Instantiating tabView";
    CellView *defaultButton = new CellView("");

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            defaultButton = new CellView("");
            defaultButton->setFixedSize(80, 80);
            defaultButton->setModel(tab->getCellAt(x, y));
            defaultButton->setIconSize(QSize(64, 64));
            Position pos = defaultButton->getModel()->getPosition();
            defaultButton->setToolTip(QString::number(pos.x) + "/" + QString::number(pos.y));

            cells->append(defaultButton);
            QObject::connect(defaultButton, SIGNAL(clickedWithPosition(Position)), this, SLOT(cellClickedHandler(Position)));
            gridLayout->addWidget(defaultButton, x , y);
        }
    }

    this->setLayout(gridLayout);
}
