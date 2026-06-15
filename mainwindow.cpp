#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dormitory.h"
#include "room.h"
#include "student.h"
#include <QMessageBox>


Dormitory myDormitory("Alpha Pavilion");
bool istInitialised = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    if (!istInitialised) {
        Room ch101("101", 2);
        Room ch102("102", 2);
        Room ch103("103", 2);

        myDormitory.addRoom(ch101);
        myDormitory.addRoom(ch102);
        myDormitory.addRoom(ch103);
        istInitialised = true;
    }


    ui->listMenu->clear();
    ui->listMenu->addItem("🍗 Couscous Poulet (Main Course)");
    ui->listMenu->addItem("🍲 Chorba Frik (Traditional Soup)");
    ui->listMenu->addItem("🥘 Tajine Zitoun (Side Dish)");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAjouterEtudiant_clicked()
{

    QString idStr = ui->txtID->text();
    QString nom = ui->txtNom->text();
    QString annee = ui->txtAnnee->text();


    if (idStr.isEmpty() || nom.isEmpty() || annee.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields!");
        return;
    }


    int id = idStr.toInt();
    Student s(id, nom.toStdString(), annee.toStdString());


    bool studentAdded = false;
    std::string numeroChambreAssignee = "";

    for (Room& chambre : myDormitory.getRooms()) {

        if (chambre.addStudent(s)) {
            studentAdded     = true;
            numeroChambreAssignee = chambre.getRoomNumber();
            break;
        }
    }


    if (studentAdded) {

        QString chambreQt = QString::fromStdString(numeroChambreAssignee);


        ui->listEtudiants->addItem(nom + " (ID: " + idStr + ") -> Assigned to Room " + chambreQt);

        ui->txtID->clear();
        ui->txtNom->clear();
        ui->txtAnnee->clear();


        QMessageBox::information(this, "Success", "Student registered and assigned to Room " + chambreQt + " successfully!");
    } else {

        QMessageBox::critical(this, "Dormitory Full", "Cannot add student: All rooms have reached their maximum capacity!");
    }
}