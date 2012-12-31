#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_configurator.h>
#include <ui_mainwindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void callConfigurationDialog();
    void updateConfiguration();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Ui::Configurator ui_configurator;
};

#endif // MAINWINDOW_H
