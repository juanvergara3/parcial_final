#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 1900, 720);

    offensive = new Canyon(0.05);
    defensive = new Canyon(0.025);

    offensive->setPosx(0);
    offensive->setPosy(0);
    defensive->setPosx(100);
    defensive->setPosy( 0);

    offensive->setEnemy_impact_radio(defensive->getImpact_multpliter());
    defensive->setEnemy_impact_radio(offensive->getImpact_multpliter());

    offensive->setDistance(defensive);
    defensive->setDistance(offensive);

    scene->addItem(offensive);
    scene->addItem(defensive);
}

MainWindow::~MainWindow() {
    delete offensive;
    delete defensive;
    delete scene;

    delete ui;
}

void MainWindow::print_results(std::vector<Shot *> shots) {

    float dt;

    for(auto k = shots.begin(); k != shots.end(); k++){

        dt = (*k)->getF_time()/10;

        for(int w = 1; w < 11; w++){
            onScreen.push_back(new Shot((*k)->getX_i(), (*k)->getY_i(), (*k)->getX(), (*k)->getY(), (*k)->getVx(), (*k)->getVy(), (*k)->getAngle(), dt*w, (*k)->getImpact_radio()));
        }
    }

    for(auto k = onScreen.begin(); k != onScreen.end(); k++){
        (*k)->set_end_pos();
        scene->addItem(*k);
    }
}

void MainWindow::on_punto1_clicked() {

    for(auto k = onScreen.begin(); k != onScreen.end(); ){
        scene->removeItem(*k);
        delete (*k);
        k = onScreen.erase(k);
    }

    scene->update();

    std::vector<Shot *> shots = offensive->generate_offensive_shots(defensive, false);

    print_results(shots);
}
void MainWindow::on_punto2_clicked() {

    for(auto k = onScreen.begin(); k != onScreen.end(); ){
        scene->removeItem(*k);
        delete (*k);
        k = onScreen.erase(k);
    }

    scene->update();

    print_results(defensive->generate_offensive_shots(offensive, false));
}
void MainWindow::on_punto3_clicked() {

}
void MainWindow::on_punto4_clicked() {

}
void MainWindow::on_punto5_clicked() {

}

void MainWindow::on_YC1_slider_sliderMoved(int position) {
    ui->YC1_lcd->display(position);
    offensive->setPosy(ui->YC1_lcd->value());
    scene->update();
}
void MainWindow::on_XC2_slider_sliderMoved(int position) {
    ui->XC2_lcd->display(position);
    defensive->setPosx(ui->XC2_lcd->value());
    scene->update();
    offensive->setDistance(defensive);
    defensive->setDistance(offensive);
}
void MainWindow::on_YC2_slider_sliderMoved(int position) {
    ui->YC2_lcd->display(position);
    defensive->setPosy(ui->YC2_lcd->value());
    scene->update();
}
