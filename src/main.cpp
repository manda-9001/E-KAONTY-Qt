#include "headers/mainwindow.h"
#include "headers/loginscreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings cfg("D:/1.Cours/hfghgf/Qt/E-kaonty/E-Kaonty/config.ini", QSettings::IniFormat);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(cfg.value("database/hostname").toString());
    db.setPort(cfg.value("database/port").toInt());
    db.setDatabaseName(cfg.value("database/name").toString());
    db.setUserName(cfg.value("database/user").toString());
    db.setPassword(cfg.value("database/password").toString());

    if (!db.open()){
        QMessageBox::critical(nullptr,"Erreur", db.lastError().text());
        return 1;
    }

    loginscreen login;

    if (login.exec() != QDialog::Accepted) return 0;

    MainWindow w;
    w.show();
    return QApplication::exec();
}
