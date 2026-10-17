#include "headers/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings cfg("config.ini", QSettings::IniFormat);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(cfg.value("database/hostname").toString());
    db.setPort(cfg.value("database/port").toInt());
    db.setDatabaseName(cfg.value("database/name").toString());
    db.setUserName(cfg.value("database/user").toString());
    db.setPassword(cfg.value("database/password").toString());
    qDebug()<<cfg.value("database/user").toString();

    if (!db.open()){
        QMessageBox::critical(nullptr,"Erreur", db.lastError().text());
        return 1;
    }
    MainWindow w;
    w.show();
    return QApplication::exec();
}
