#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    QString credits = QString("<a href=\"http:\/\/www.freepik.com/free-vector/chess-pieces-vector_750283.htm\">Designed by Freepik</a>");
}

MainWindow::~MainWindow()
{

}

void MainWindow::registerTabView(TabView *view)
{
    layout->addWidget(view, 0, 0);

    this->setLayout(layout);
}
