#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecounter.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBoxN->setRange(0, MAX_N_POINTS);
    ui->spinBoxG->setRange(0, MAX_G_POINTS);
    ui->spinBoxP->setRange(0, MAX_P_POINTS);
    ui->spinBoxE->setRange(0, 5);

    connect(ui->countPushButton, &QPushButton::clicked, this, &MainWindow::printGrade);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBoxN_valueChanged(int arg1)
{
    n_points = arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    g_points = arg1;
}


void MainWindow::on_spinBoxP_valueChanged(int arg1)
{
    p_points = arg1;
}


void MainWindow::on_spinBoxE_valueChanged(int arg1)
{
    exam_grade = arg1;
}


void MainWindow::on_countPushButton_clicked()
{
    final_grade = count_final_grade(n_points, g_points, p_points, exam_grade);
}

void MainWindow::printGrade()
{
    ui->textBrowser->setText(QString("Total grade: %1").arg(final_grade));
}

