#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "tabview.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void registerTabView(TabView *view);

signals:

public slots:

private:
    QGridLayout *layout;
};

#endif // MAINWINDOW_H
