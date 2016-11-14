#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <findandreplace.h>
#include <qtextformat.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void findNext(QString);

    void findPrevious(QString);

    void replaceNext(QString,QString);

    void replacePrevious(QString,QString);

private slots:
    QString getFileNameFromPath(QString);

    QString getFileDirFromPath(QString);

    void closeEvent(QCloseEvent*);

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_Notepad_triggered();

    void on_textEdit_textChanged();

    void on_actionChoose_Font_triggered();

    void on_action_Exit_triggered();

    void on_actionInsert_Date_triggered();

    void on_action_Find_and_Replace_triggered();

private:
    Ui::MainWindow *ui;
    FindAndReplace *findAndReplace;
    QString file_path;
    QString file_dir;
    QString file_name;
    bool file_changed;
};

#endif // MAINWINDOW_H
