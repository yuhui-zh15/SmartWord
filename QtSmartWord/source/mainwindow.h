#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::string username, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_queryButton_clicked();
    void on_pushButton_clicked();
    void on_loadButton_clicked();
    void on_addExampleButton_clicked();
    void on_addWordButton_clicked();
    void on_modifyWordButton_clicked();
    void on_startButton_clicked();
    void on_deleteButton_clicked();
    void on_deleteAllButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_addToListButton_clicked();
    void on_deleteMyWord_clicked();
    void on_deleteAllMyWord_clicked();
    void on_saveInfoButton_clicked();
    void on_loadInfoButton_clicked();
    void on_translateButton_clicked();
    void on_startTestButton_clicked();
    void on_testConfirmButton_clicked();
    void on_testNextButton_clicked();
    void on_testPrevButton_clicked();
    void on_addToListButtonInSearch_clicked();


    void on_loadExampleButton_clicked();

private:
    Ui::MainWindow *ui;
    std::string username;
};

#endif // MAINWINDOW_H
