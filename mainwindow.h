#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<qstring.h>
#include"functions.h"
#include"class_student.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void sub_close();
    void seek_output();
    int check_input_mistake();
    int check_score();
    int score(int a);
    void check_subject();
    void cout_stu_info();
    void sleep(unsigned int);
    int score_empty(QString a);
    int check_major(QString a);
    void five_info_show(student *s);
    ~MainWindow();




private slots:
    void on_action_add_triggered();

    void on_action_search_triggered();

    void on_action_del_triggered();

    void on_pushButton_delete_clicked();

    void on_action_sort_triggered();

    void on_action_save_triggered();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_action_mainmenu_triggered();

    void on_back_to_menu_3_clicked();

    void on_back_to_menu_clicked();

    void on_back_to_menu_2_clicked();

    void on_pushButton_5_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
