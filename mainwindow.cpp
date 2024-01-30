#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString str = ui->lineEdit->text();
    NewValidator emailValidator;
    if (ui->lineEdit->text().isEmpty())
    {
        ui->label_2->setText("Помилка. Ви нічого не ввели.");
        ui->label_2->setStyleSheet("color: red;");
    }
    else
    {
        if (emailValidator.isValid(str))
        {
            ui->label_2->setText("Введений рядок може бути дійсною електронною адресою.");
            ui->label_2->setStyleSheet("color: green;");
        }
        else
        {
            ui->label_2->setText("Введений рядок не може бути дійсною електронною адресою.");
            ui->label_2->setStyleSheet("color: red;");
        }
    }

}


void MainWindow::on_pushButton_clicked()
{
    on_lineEdit_returnPressed();
}

