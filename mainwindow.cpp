#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Fill the screen with the text box, leaving no empty margins
    this->setCentralWidget(ui->textEdit);

    //Initializes window title
    ui->statusBar->setWindowTitle("New Document - Notepad");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    //TODO: code for unsaved changes

    //Resets path var and clears text box
    file_path = "";
    ui->textEdit->setText("");
}

//TODO: Make it remember the last directory you open, so it doesn't keep reverting to dir of executable
//TODO: Make title reflect the name of the file you have open
void MainWindow::on_actionOpen_triggered()
{
    //Specifies what types of files the program can open
    QString filters = "Text File (*.txt);;All Files (*.*)";

    //Prompts user with file dialog to locate desired file
    file_path = QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath(),filters);

    //Attempt to open file
    QFile file(file_path);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        //If file fails to open, display error and exit method
        QMessageBox::warning(this, "Error", "Error opening file");
        return;
    }

    //Read in text from file
    QTextStream in(&file);
    QString text = in.readAll();

    //Display on screen
    ui->textEdit->setText(text);

    //Close file
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    //If no file has been selected, call save as instead
    if (file_path.length() == 0){
        MainWindow::on_actionSave_As_triggered();
        return;
    }

    //Attempt to open file
    QFile file(file_path);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        //If file fails to open, display error and exit method
        QMessageBox::warning(this, "Error", "Error saving file");
        return;
    }

    //Connect text stream to file for output, then write to file
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    //Flush stream and close file
    out.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    //Specifies what types of files the program can open
    QString filters = "Text File (*.txt);;All Files (*.*)";

    //Prompts user with file dialog to locate desired file
    file_path = QFileDialog::getSaveFileName(this,"Save File",QDir::currentPath(),filters);

    //Attempt to open file
    QFile file(file_path);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        //If file fails to open, display error and exit method
        QMessageBox::warning(this, "Error", "Error saving file");
        return;
    }

    //Connect text stream to file for output, then write to file
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    //Flush stream and close file
    out.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_Notepad_triggered()
{
    QMessageBox::information(this,"About Notepad","Notepad\nVersion .1, Rev 0\nDate of release: 10/26/16\nLicense: GNU General Public License\nAuthor: Steven Karr\nContact: stevenkarr93@gmail.com");
}
