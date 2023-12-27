#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLineEdit>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(calculateCalories()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateCalories()
{
    int time = ui->timeLineEdit->text().toInt();
    int weight = ui->weightLineEdit->text().toInt();
    int pulse = ui->pulseLineEdit->text().toInt();
    double result = (0.014 * weight * time * (0.12 * pulse - 7));
    ui->resultLineEdit->setText(QString::number(result));
}

void MainWindow::on_calculateButton_clicked()
{
    calculateCalories();
}

