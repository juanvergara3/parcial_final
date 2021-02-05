#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "canyon.h"

#define v_limit 720

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private: // variables
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    Canyon *defensive, *offensive;

    std::list<Shot*> onScreen;

public: // variables

private: // methods
    void print_results(std::vector<Shot *> shots);
    void print_results(Shot* shot);

public: // methods
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_punto1_clicked();
    void on_punto2_clicked();
    void on_punto3_clicked();
    void on_punto4_clicked();
    void on_punto5_clicked();

    void on_YC1_slider_sliderMoved(int position);
    void on_XC2_slider_sliderMoved(int position);
    void on_YC2_slider_sliderMoved(int position);
};
#endif // MAINWINDOW_H
