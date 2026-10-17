#include "headers/loginscreen.h"
#include "ui_loginscreen.h"

loginscreen::loginscreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginscreen)
{
    ui->setupUi(this);
    setWindowTitle("E-Kaonty - Connexion");
    auto *label = new QLabel();
    label->setText("E-KAONTY");
    label->setStyleSheet("font-size: 30pt;font-weight:bold;");
    label->setAlignment(Qt::AlignCenter);
    auto *nomEdit = new QLineEdit();
    auto *mdp = new QLineEdit();
    mdp->setMaximumWidth(250);
    mdp->setMaximumWidth(250);
    nomEdit->setMinimumWidth(200);
    mdp->setMinimumWidth(200);
    mdp->setEchoMode(QLineEdit::Password);
    auto *btnlogin = new QPushButton("Se connecter");

    auto *form = new QFormLayout;
    form->addRow("Nom: ",nomEdit);
    form->addRow("Mot de passe", mdp);
    form->addWidget(btnlogin);

    auto *H = new QHBoxLayout;
    H->addStretch();
    H->addLayout(form);
    H->addStretch();

    auto *V = new QVBoxLayout;
    V->addWidget(label);
    V->addStretch();
    V->addLayout(H);
    V->addStretch();

    setLayout(V);

    connect(btnlogin,&QPushButton::clicked, this, [=](){
        QString nom = nomEdit->text().trimmed();
        QString hash = QCryptographicHash::hash(mdp->text().toUtf8(), QCryptographicHash::Sha256).toHex();
        QSqlQuery q;
        q.prepare("SELECT id FROM personne WHERE nom = :nom AND mdp = :mdp");
        q.bindValue(":nom",nom);
        q.bindValue(":mdp", hash);

        if (!q.exec()){
            QMessageBox::critical(this,"Erreur", q.lastError().text());
        }
        if (q.next()) accept();
        else QMessageBox::warning(this, "Erreur","Nom ou mot de passe incorrect");
    });
}

loginscreen::~loginscreen()
{
    delete ui;
}
