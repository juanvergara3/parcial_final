#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_punto1_clicked()
{

}
void MainWindow::on_punto2_clicked()
{

}
void MainWindow::on_punto3_clicked()
{

}
void MainWindow::on_punto4_clicked()
{

}
void MainWindow::on_punto5_clicked()
{

}

void MainWindow::on_YC1_slider_sliderMoved(int position) {
    ui->YC1_lcd->display(position);
}
void MainWindow::on_XC2_slider_sliderMoved(int position) {
    ui->XC2_lcd->display(position);
}
void MainWindow::on_YC2_slider_sliderMoved(int position) {
    ui->YC2_lcd->display(position);
}
