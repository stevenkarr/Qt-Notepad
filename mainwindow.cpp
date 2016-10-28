#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Fill the screen with the text box, leaving no empty margins
    this->setCentralWidget(ui->textEdit);

    //Initializes window title
    MainWindow::setWindowTitle("New Document - Notepad");

    //Initializes change var
    file_changed = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Extracts a file name from a path. i.e. "C:/example.txt" -> "example.txt"
QString MainWindow::getFileNameFromPath(QString path){
    //We will build the string containing the filename backwards
    QString filename = "";

    //Look at each char, starting form the end
    for (int i = path.length()-1; i >= 0; i--){
        //Char at current position
        QChar c = path[i];

        //Appends the current char if it is not our termination symbol, '/'
        if (c != QChar('/')){
            filename = c + filename;
        }
        //Else if we find the symbol, we've finished building the filename
        else {
            return filename;
        }
    }

    return filename;
}

void MainWindow::on_actionNew_triggered()
{
    //Checks if the user has unsaved changes, asks to confirm action
    if (file_changed){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Notepad", "The document contains unsaved changes. Are you sure you wish to proceed?",QMessageBox::Yes|QMessageBox::No);
        //Exits method if they answer no, else proceeds normally
        if (reply == QMessageBox::No){
            return;
        }
    }

    //Resets tracking vars and clears text box
    file_path = "";
    file_name = "";
    ui->textEdit->setText("");

    //Set window title to reflect new document
    MainWindow::setWindowTitle("New Document - Notepad");

    //This var must be reset after setting the window title because textChanged()
    // will be called from the previous line
    file_changed = false;
}

void MainWindow::on_actionOpen_triggered()
{
    //Checks if the user has unsaved changes, asks to confirm action
    if (file_changed){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Notepad", "The document contains unsaved changes. Are you sure you wish to proceed?",QMessageBox::Yes|QMessageBox::No);
        //Exits method if they answer no, else proceeds normally
        if (reply == QMessageBox::No){
            return;
        }
    }

    //Specifies what types of files the program can open
    QString filters = "Text File (*.txt);;All Files (*.*)";

    //Prompts user with file dialog to locate desired file
    file_path = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath(),filters);

    //Obtains file name
    file_name = getFileNameFromPath(file_path);

    //Attempt to open file
    QFile file(file_path);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        //If file fails to open, exit method
        return;
    }

    //Read in text from file
    QTextStream in(&file);
    QString text = in.readAll();

    //Display on screen
    ui->textEdit->setText(text);

    //Sets window title to reflect opened file name
    MainWindow::setWindowTitle(file_name + " - Notepad");
    file_changed = false;

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

    //Attempt to save to file
    QFile file(file_path);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        //If file fails to open, display error and exit method
        QMessageBox::warning(this, "Error", "Error saving file");
        return;
    }

    //Updates window title if necessary
    if (file_changed){
        MainWindow::setWindowTitle(file_name + " - Notepad");
        file_changed = false;
    }

    //Connect text stream to file for output, then write to file
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    //Flush stream and close file
    out.flush();
    file.close();

    //Reset changed bool
    file_changed = false;
}

void MainWindow::on_actionSave_As_triggered()
{
    //Specifies what types of files the program can open
    QString filters = "Text File (*.txt);;All Files (*.*)";

    //Prompts user with file dialog to locate desired file
    file_path = QFileDialog::getSaveFileName(this,"Save File",QDir::homePath(),filters);

    //Attempt to open file
    QFile file(file_path);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        //If file fails to open exit method
        return;
    }

    //Obtains file name
    file_name = getFileNameFromPath(file_path);

    //Updates window title with newly specified filename
    MainWindow::setWindowTitle(file_name + " - Notepad");

    //Connect text stream to file for output, then write to file
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    //Flush stream and close file
    out.flush();
    file.close();

    //Reset changed bool
    file_changed = false;
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
    QMessageBox::information(this,"About Notepad","Notepad\nVersion .9, Rev 0\nDate of release: 10/26/16\nLicense: GNU General Public License\nAuthor: Steven Karr\nContact: stevenkarr93@gmail.com");
}

//The purpose of the code here is to append an asterisk to the name on the
// window title to demonstrate the file is changed, and notify the user should
// they attempt to close or open a file with unsaved changes to the
// current document.
void MainWindow::on_textEdit_textChanged()
{
    //If we've found user has made a change..
    if (!file_changed){
        //Set flag var
        file_changed = true;
        //If a file has been opened, we have a filename to work with
        if (file_name.length() > 0){
            MainWindow::setWindowTitle(file_name + "* - Notepad");
        }
        //Otherwise we don't, and we're using the filler "New Document" name
        else {
            MainWindow::setWindowTitle("New Document* - Notepad");        }
    }
}

//Confirms the user exiting the application if there are unsaved changes
void MainWindow::closeEvent(QCloseEvent *event)
{
    //Quits normally if no unsaved changes in current document
    if (!file_changed){
        return;
    }

    //Else, prompts user to confirm quitting with unsaved changes
    QMessageBox::StandardButton reply = QMessageBox::question( this, tr("Notepad"),
                                                                     tr("The document contains unsaved changes. Are you sure you wish to exit?"),
                                                                     QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}
