#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void MainWindow::on_actionNew_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    ui->textEdit->setText(text);
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionExit_triggered()
{

}


void MainWindow::on_actionAbout_Notepad_triggered()
{

}


void MainWindow::on_actionSave_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    ui->textEdit->setText(text);
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionHelp_triggered()
{

}


void MainWindow::on_actionDelete_triggered()
{

}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

