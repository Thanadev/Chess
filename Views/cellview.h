#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QPushButton>
#include "../Persistents/chesscell.h";
#include "../Persistents/Utils/position.h";

class CellView : public QPushButton
{
    Q_OBJECT
public:
    CellView(QWidget *parent=0);
    CellView(const QString &text, QWidget *parent=0);
    CellView(const QIcon& icon, const QString &text, QWidget *parent=0);
    ~CellView();
    void setModel(ChessCell *cell);
    void updateView();
    ChessCell* getModel() const;
signals:
    void clickedWithPosition(Position pos);
private slots:
    void clickedHandler();
private:
    void initCell();

    ChessCell *model;
};

#endif // CELLVIEW_H
