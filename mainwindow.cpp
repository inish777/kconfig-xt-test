#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <KConfigDialog>
#include "configurator.h"
#include "ui_configurator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(callConfigurationDialog()));
    ui->lineEdit->setText(Settings::line());
    ui->fontComboBox->setCurrentFont(Settings::font());
    ui->checkBox->setCheckState((Qt::CheckState)Settings::checkBox());
    ui->spinBox->setValue(Settings::spinBox());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callConfigurationDialog()
{
    // An instance of your dialog could be already created and could be
    // cached, in which case you want to display the cached dialog
    // instead of creating another one
    if ( KConfigDialog::showDialog( "settings" ) )
      return;
    // KConfigDialog didn't find an instance of this dialog, so lets
    // create it :
    KConfigDialog* dialog = new KConfigDialog(this, "settings",
                                              Settings::self());
    QDialog* settingsDlg = new QDialog;
    ui_configurator.setupUi(settingsDlg);
    dialog->addPage(settingsDlg, i18n("Settings"), "settings");
    // User edited the configuration - update your local copies of the
    // configuration data
    connect( dialog, SIGNAL(settingsChanged(QString)),
             this, SLOT(updateConfiguration()) );

    dialog->show();
}

void MainWindow::updateConfiguration()
{
    ui->lineEdit->setText(Settings::line());
    ui->fontComboBox->setCurrentFont(Settings::font());
    ui->checkBox->setCheckState((Qt::CheckState)Settings::checkBox());
    ui->spinBox->setValue(Settings::spinBox());
}
