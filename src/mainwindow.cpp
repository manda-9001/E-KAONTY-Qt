#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("E-Kaonty");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnsold_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Solde);
}

