#ifndef TABVIEW_H
#define TABVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QDebug>

#include "cellview.h"
#include "../Persistents/chesstab.h"

class TabView : public QWidget
{
    Q_OBJECT
public:
    explicit TabView(QWidget *parent = 0);
    ~TabView();
    void instantiateTab(const ChessTab *tab);
    void updateView();
signals:
    void cellClickedWithPos(Position pos);
private slots:
    void cellClickedHandler(Position pos);
private:
    QGridLayout *gridLayout;
    QList<CellView *> *cells;
};

#endif // TABVIEW_H
