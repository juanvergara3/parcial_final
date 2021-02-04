#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
