#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closePushButton, &QPushButton::clicked, this, &MainWindow::closeDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeDialog()
{
    this->close();
}

