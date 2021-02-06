#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 1900, 720);

    offensive = new Canyon(0.05, "o");
    defensive = new Canyon(0.025, "d");

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

void MainWindow::print_shots(std::vector<Shot *> shots) {

    float dt;

    for(auto k = shots.begin(); k != shots.end(); k++){

        dt = (*k)->getF_time()/ui->principal_box->value();

        (*k)->setRadio(ui->r_principal->isChecked());

        for(int w = 1; w < ui->principal_box->value() + 1; w++){
            onScreen.push_back(new Shot((*k)->getX_i(), (*k)->getY_i(), (*k)->getX(), (*k)->getY(), (*k)->getVx(), (*k)->getVy(), (*k)->getAngle(), dt*w, (*k)->getImpact_radio(), (*k)->getType(), (*k)->getRadio()));
        }
    }

    for(auto k = onScreen.begin(); k != onScreen.end(); k++){
        (*k)->set_end_pos();
        scene->addItem(*k);
    }
}
void MainWindow::add_shot(Shot *shot) {
    float dt;

    dt = shot->getF_time()/ui->secundario_box->value();

    shot->setRadio(ui->r_secundario->isChecked());

    for(int w = 1; w < ui->secundario_box->value() + 1 ; w++)
        onScreen.push_back(new Shot(shot->getX_i(), shot->getY_i(), shot->getX(), shot->getY(), shot->getVx(), shot->getVy(), shot->getAngle(), dt*w, shot->getImpact_radio(), shot->getType(), shot->getRadio()));

    for(auto k = onScreen.begin(); k != onScreen.end(); k++){
        (*k)->set_end_pos();
    }
}
void MainWindow::display_shots(std::vector<Shot *> shots) {

    if(shots.size() == 3){

        Shot *one = shots[0], *two = shots[1], *three = shots[2];

        ui->angle_lcd1->display(one->getAngle());
        ui->velocity_lcd1->display(one->getV0());
        ui->posx_lcd1->display(one->getX());
        ui->posy_lcd1->display(one->getY());
        ui->time_lcd1->display(one->getF_time());

        ui->angle_lcd2->display(two->getAngle());
        ui->velocity_lcd2->display(two->getV0());
        ui->posx_lcd2->display(two->getX());
        ui->posy_lcd2->display(two->getY());
        ui->time_lcd2->display(two->getF_time());

        ui->angle_lcd3->display(three->getAngle());
        ui->velocity_lcd3->display(three->getV0());
        ui->posx_lcd3->display(three->getX());
        ui->posy_lcd3->display(three->getY());
        ui->time_lcd3->display(three->getF_time());
    }
    else if(shots.size() == 2){

        Shot *one = shots[0], *two = shots[1];

        ui->angle_lcd1->display(one->getAngle());
        ui->velocity_lcd1->display(one->getV0());
        ui->posx_lcd1->display(one->getX());
        ui->posy_lcd1->display(one->getY());
        ui->time_lcd1->display(one->getF_time());

        ui->angle_lcd2->display(two->getAngle());
        ui->velocity_lcd2->display(two->getV0());
        ui->posx_lcd2->display(two->getX());
        ui->posy_lcd2->display(two->getY());
        ui->time_lcd2->display(two->getF_time());

        ui->angle_lcd3->display(0);
        ui->velocity_lcd3->display(0);
        ui->posx_lcd3->display(0);
        ui->posy_lcd3->display(0);
        ui->time_lcd3->display(0);
    }
    else if(shots.size() == 1){

        Shot *one = shots[0];

        ui->angle_lcd1->display(one->getAngle());
        ui->velocity_lcd1->display(one->getV0());
        ui->posx_lcd1->display(one->getX());
        ui->posy_lcd1->display(one->getY());
        ui->time_lcd1->display(one->getF_time());

        ui->angle_lcd2->display(0);
        ui->velocity_lcd2->display(0);
        ui->posx_lcd2->display(0);
        ui->posy_lcd2->display(0);
        ui->time_lcd2->display(0);

        ui->angle_lcd3->display(0);
        ui->velocity_lcd3->display(0);
        ui->posx_lcd3->display(0);
        ui->posy_lcd3->display(0);
        ui->time_lcd3->display(0);
    }
    else if(shots.size() == 0){

        reset_dials();
    }
}

void MainWindow::clear_scene() {
    for(auto k = onScreen.begin(); k != onScreen.end(); ){
        scene->removeItem(*k);
        delete (*k);
        k = onScreen.erase(k);
    }

    scene->update();
}
void MainWindow::reset_dials() {
    ui->angle_lcd1->display(0);
    ui->velocity_lcd1->display(0);
    ui->posx_lcd1->display(0);
    ui->posy_lcd1->display(0);
    ui->time_lcd1->display(0);

    ui->angle_lcd2->display(0);
    ui->velocity_lcd2->display(0);
    ui->posx_lcd2->display(0);
    ui->posy_lcd2->display(0);
    ui->time_lcd2->display(0);

    ui->angle_lcd3->display(0);
    ui->velocity_lcd3->display(0);
    ui->posx_lcd3->display(0);
    ui->posy_lcd3->display(0);
    ui->time_lcd3->display(0);
}

void MainWindow::on_punto1_clicked() {

    clear_scene();

    std::vector<Shot *> shots = offensive->generate_offensive_shots(defensive);

    display_shots(shots);
    print_shots(shots);
}
void MainWindow::on_punto2_clicked() {

    clear_scene();

    std::vector<Shot *> shots = defensive->generate_offensive_shots(offensive);

    display_shots(shots);
    print_shots(shots);
}
void MainWindow::on_punto3_clicked() {

    clear_scene();

    Shot *s = offensive->generate_offensive_shots(defensive)[0];

    if(defensive->confirm_impact(offensive, s)){
        add_shot(s);

        std::vector<Shot *> shots = defensive->generate_defensive_shots(offensive, s, false);

        display_shots(shots);
        print_shots(shots);
    }
}
void MainWindow::on_punto4_clicked() {

    clear_scene();

    Shot *s = offensive->generate_offensive_shots(defensive)[0];

    if(defensive->confirm_impact(offensive, s)){
        add_shot(s);

        std::vector<Shot *> shots = defensive->generate_defensive_shots(offensive, s, true);

        display_shots(shots);
        print_shots(shots);
    }
}
void MainWindow::on_punto5_clicked() {

    clear_scene();

    Shot *of = offensive->generate_offensive_shots(defensive)[0];
    Shot *def = defensive->generate_defensive_shots(offensive, of, false)[0];

    std::vector<Shot *> shots = offensive->generate_counter_offensive_shots(defensive, def, of);

    if(shots.size() == 0){

        clear_scene();
        reset_dials();
    }
    else{
        add_shot(of);
        add_shot(def);

        display_shots(shots);
        print_shots(shots);
    }
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
