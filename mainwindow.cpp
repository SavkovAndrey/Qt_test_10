#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem *item_1 = new QListWidgetItem(QIcon(":/rec/img/1.png"), "Audi");
    QListWidgetItem *item_2 = new QListWidgetItem(QIcon(":/rec/img/2.png"), "BMW");
    QListWidgetItem *item_3 = new QListWidgetItem(QIcon(":/rec/img/exit.png"), "Volvo");
    ui->listWidget->addItem(item_1);     // добавление строк в listWidget
    ui->listWidget->addItem(item_2);     // можно добавлять просто "Audi" (тогда будет только надпись)
    ui->listWidget->addItem(item_3);     // а можно как в примере , тогда будет картинка и текст
    ui->listWidget->addItem("Ford");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    ui->statusbar->showMessage("Создание нового проекта");
}


void MainWindow::on_action_2_triggered()
{
      ui->statusbar->showMessage("Открытие нового проекта");
}


void MainWindow::on_action_3_triggered()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_clicked()
{      // по нажатию кнопки, показать в статус-баре текст из listWidget
    ui->statusbar->showMessage(ui->listWidget->currentItem()->text());

    // применение стилей к listWidget
    ui->listWidget->currentItem()->setBackgroundColor(Qt::blue);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}

