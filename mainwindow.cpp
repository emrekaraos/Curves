#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->ui->spinScale->setValue(this->ui->renderarea->scale());
    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderarea->setSahpe(renderArea::Astroid);
    this->ui->renderarea->repaint();
    update_ui();
}


void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderarea->setSahpe(renderArea::Cycloid);
    this->ui->renderarea->repaint();
    update_ui();
}


void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderarea->setSahpe(renderArea::HuygensCycloid);
    this->ui->renderarea->repaint();
    update_ui();
}


void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderarea->setSahpe(renderArea::HypoCycloid);
    this->ui->renderarea->repaint();
    update_ui();
}


void MainWindow::on_btnline_clicked()
{
    this->ui->renderarea->setSahpe(renderArea::line);
    this->ui->renderarea->repaint();
    update_ui();
}


void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderarea->setScale(scale);
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderarea->scale());
    this->ui->spinLenght->setValue(this->ui->renderarea->length());
    this->ui->spinStepCount->setValue(this->ui->renderarea->stepCount());
}


void MainWindow::on_spinLenght_valueChanged(double intervalLenght)
{
    this->ui->renderarea->setLenght(intervalLenght);
}


void MainWindow::on_spinStepCount_valueChanged(int count)
{
    this->ui->renderarea->setStepCount(count);
}


void MainWindow::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderarea->backgroundColor(), this, "Select Color");
    ui->renderarea->setBackgroundColor(color);
}


void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderarea->shapeColor(), this, "Select Color");
    ui->renderarea->setShapeColor(color);
}

