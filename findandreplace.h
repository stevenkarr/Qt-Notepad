#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H
//#include <qmainwindow.h>

#include <QDialog>

class MainWindow;

namespace Ui {
class FindAndReplace;
}

class FindAndReplace : public QDialog
{
    Q_OBJECT

public:
    explicit FindAndReplace(MainWindow *parent = 0);
    ~FindAndReplace();

private slots:
    void on_pushButton_findNext_clicked();

    void on_pushButton_findPrevious_clicked();

    void on_pushButton_replaceNext_clicked();

    void on_pushButton_replacePrevious_clicked();

private:
    Ui::FindAndReplace *ui;
    MainWindow *mwParent;
};

#endif // FINDANDREPLACE_H
