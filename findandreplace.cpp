#include "findandreplace.h"
#include "ui_findandreplace.h"
#include <QTextEdit>
#include <mainwindow.h>

FindAndReplace::FindAndReplace(MainWindow *parent) :
       ui(new Ui::FindAndReplace)
{
    ui->setupUi(this);

    //Assigns parent var
    mwParent = parent;

    //Set focus so that user can immediately start typing
    ui->lineEdit_Find->setFocus();

    //Initializes findAll tracker
    findingAll = false;
}

FindAndReplace::~FindAndReplace()
{
    delete ui;
}


void FindAndReplace::on_pushButton_findNext_clicked()
{
    //Check if search box is empty. If so, do nothing
    if (ui->lineEdit_Find->text().length() == 0){
        return;
    }
    else {

        mwParent->findNext(ui->lineEdit_Find->text());
        return;
    }
}

void FindAndReplace::on_pushButton_findPrevious_clicked()
{
    //Check if search box is empty. If so, do nothing
    if (ui->lineEdit_Find->text().length() == 0){
        return;
    }
    else {
        mwParent->findPrevious(ui->lineEdit_Find->text());
        return;
    }
}

void FindAndReplace::on_pushButton_replaceNext_clicked()
{
    //Check if search box is empty. If so, do nothing
    if (ui->lineEdit_Replace_Find->text().length() == 0 ||
            ui->lineEdit_Replace_With->text().length() == 0){
        return;
    }
    else {
        mwParent->replaceNext(ui->lineEdit_Replace_Find->text(),
                              ui->lineEdit_Replace_With->text());
        return;
    }
}

void FindAndReplace::on_pushButton_replacePrevious_clicked()
{
    //Check if search box is empty. If so, do nothing
    if (ui->lineEdit_Replace_Find->text().length() == 0 ||
            ui->lineEdit_Replace_With->text().length() == 0){
        return;
    }
    else {
        mwParent->replacePrevious(ui->lineEdit_Replace_Find->text(),
                              ui->lineEdit_Replace_With->text());
        return;
    }
}
