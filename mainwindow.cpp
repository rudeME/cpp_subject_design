#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QPushButton>
#include<QMessageBox>
#include<QTime>
#include<QFont>
int total_score_flag=1;
student *s;//用于获取add返回的指针，来修改成绩
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("学生信息查询系统");
    resize(900,600);
    ui->stackedWidget->setCurrentWidget(ui->else_2);

    QFont font;
    font.setPointSize(30);
    ui->label_menu->setFont(font);
   //MainWindow::sub_close();
//    ui->del_num->setText("输入你想操作的学生编号");
/**************************BUTTON*************************************************************/
//add_button
    connect(ui->add_button,QPushButton::clicked,[=](){

        //检错
        int b = MainWindow:: check_input_mistake();
        int c = MainWindow::check_score();

        QString number= ui->number->text();
        QString name=ui->name->text();
        QString sex=ui->sex->currentText();
//        QString major=ui->major->text();
        QString major=ui->combo_major->currentText();
        int class_2=ui->class_2->text().toInt();
        const char * cStr1 = number . toStdString ( ) . c_str ( ) ;
        const char * cStr2 = name . toStdString ( ) . c_str ( ) ;
        const char * cStr3 = sex . toStdString ( ) . c_str ( ) ;
        const char * cStr4 = major . toStdString ( ) . c_str ( ) ;

        if(b&&c)
        {
            s=add(cStr1,cStr2,cStr3,cStr4,class_2);//五项基本信息输入，返回学生指针

//            qDebug()<<s->get_check();
            //关于成绩的相关输入还没好  一个坑 留意
            //已填
            //后端检错
            if(s->get_check())//后端检测输入错误或者有覆盖
            {
                if(s->get_check()==1)
                    QMessageBox::about(this,"error","参数过长");
                else if(s->get_check()==2)
                    QMessageBox::about(this,"error","学号错误");
                else if(s->get_check()==4)
                    QMessageBox::about(this,"error","学院错误");
                else if(s->get_check()==5)
                    QMessageBox::about(this,"error","已覆盖先前的记录");
                else if(s->get_check()==6)
                    QMessageBox::about(this,"error","班级错误");
                else if(s->get_check()==7)
                    QMessageBox::about(this,"error","姓名非法");

            }
            else
            {
                if(b&&c)
                    QMessageBox::about(this,"提示","添加成功");

            }


            QString gaoshu=ui->lineEdit_gaoshu->text();
            QString xiandai=ui->lineEdit_xiandai->text();
            QString chengxu=ui->lineEdit_chengxu->text();
            QString gaitong=ui->lineEdit_gaitong->text();
            QString dianzi=ui->lineEdit_dianzi->text();
            QString jinshi=ui->lineEdit_jinshi->text();
            QString cwf=ui->lineEdit_cwf->text();
            QString xinhao=ui->lineEdit_xinhao->text();
            QString os=ui->lineEdit_os->text();
            QString wangluo=ui->lineEdit_wangluo->text();


            if(score_empty(gaoshu)!=-5)
            {
                const char* str=ui->label_gaoshu ->text().toStdString().c_str();

                s->modify_score(str,score_empty(gaoshu));
            }

            if(score_empty(xiandai)!=-5)
            {
                const char* str=ui->label_xiandai ->text().toStdString().c_str();
                s->modify_score(str,score_empty(xiandai));
            }
            if(score_empty(chengxu)!=-5)
            {
                const char* str=ui->label_chengxu ->text().toStdString().c_str();
                s->modify_score(str,score_empty(chengxu));
            }
            if(score_empty(gaitong)!=-5)
            {
                const char* str=ui->label_gaitong ->text().toStdString().c_str();
                s->modify_score(str,score_empty(gaitong));
            }
            if(score_empty(dianzi)!=-5)
            {
                const char* str=ui->label_dianzi ->text().toStdString().c_str();
                s->modify_score(str,score_empty(dianzi));
            }
            if(score_empty(jinshi)!=-5)
            {
                const char* str=ui->label_jinshi ->text().toStdString().c_str();
                s->modify_score(str,score_empty(jinshi));
            }
            if(score_empty(cwf)!=-5)
            {
                const char* str=ui->label_cwf ->text().toStdString().c_str();
                s->modify_score(str,score_empty(cwf));
            }
            if(score_empty(xinhao)!=-5)
            {
                const char* str=ui->label_xinhao ->text().toStdString().c_str();
                s->modify_score(str,score_empty(xinhao));
            }
            if(score_empty(os)!=-5)
            {
                const char* str=ui->label_os ->text().toStdString().c_str();
                s->modify_score(str,score_empty(os));
            }
            if(score_empty(wangluo)!=-5)
            {
                const char* str=ui->label_wangluo ->text().toStdString().c_str();
                s->modify_score(str,score_empty(wangluo));
            }


        }

    });

    /*
pushbutton_modify_score添加修改成绩
    connect(ui->modify_score,QPushButton::clicked,[=](){
        QString gaoshu=ui->lineEdit_gaoshu->text();
        QString xiandai=ui->lineEdit_xiandai->text();
        QString chengxu=ui->lineEdit_chengxu->text();
        QString gaitong=ui->lineEdit_gaitong->text();
        QString dianzi=ui->lineEdit_dianzi->text();
        QString jinshi=ui->lineEdit_jinshi->text();
        QString cwf=ui->lineEdit_cwf->text();
        QString xinhao=ui->lineEdit_xinhao->text();
        QString os=ui->lineEdit_os->text();
        QString wangluo=ui->lineEdit_wangluo->text();

        int c = MainWindow::check_score();

        if(score_empty(gaoshu)!=-5)
        {
            const char* str=ui->label_gaoshu ->text().toStdString().c_str();

            s->modify_score(str,score_empty(gaoshu));
        }

        if(score_empty(xiandai)!=-5)
        {
            const char* str=ui->label_xiandai ->text().toStdString().c_str();
            s->modify_score(str,score_empty(xiandai));
        }
        if(score_empty(chengxu)!=-5)
        {
            const char* str=ui->label_chengxu ->text().toStdString().c_str();
            s->modify_score(str,score_empty(chengxu));
        }
        if(score_empty(gaitong)!=-5)
        {
            const char* str=ui->label_gaitong ->text().toStdString().c_str();
            s->modify_score(str,score_empty(gaitong));
        }
        if(score_empty(dianzi)!=-5)
        {
            const char* str=ui->label_dianzi ->text().toStdString().c_str();
            s->modify_score(str,score_empty(dianzi));
        }
        if(score_empty(jinshi)!=-5)
        {
            const char* str=ui->label_jinshi ->text().toStdString().c_str();
            s->modify_score(str,score_empty(jinshi));
        }
        if(score_empty(cwf)!=-5)
        {
            const char* str=ui->label_cwf ->text().toStdString().c_str();
            s->modify_score(str,score_empty(cwf));
        }
        if(score_empty(xinhao)!=-5)
        {
            const char* str=ui->label_xinhao ->text().toStdString().c_str();
            s->modify_score(str,score_empty(xinhao));
        }
        if(score_empty(os)!=-5)
        {
            const char* str=ui->label_os ->text().toStdString().c_str();
            s->modify_score(str,score_empty(os));
        }
        if(score_empty(wangluo)!=-5)
        {
            const char* str=ui->label_wangluo ->text().toStdString().c_str();
            s->modify_score(str,score_empty(wangluo));
        }

        if(c)
            QMessageBox::about(this,"成绩","已修改");

    });

*/



//pushButton_search 查找
    connect(ui->pushButton_search,QPushButton::clicked,[=](){
        //清屏
        ui->textBrowser->setText("");

        QString number= ui->number_2->text();
        QString name=ui->name_2->text();
        if(!QString(number).isEmpty())//根据学号查找
        {

            const char * cStr = number . toStdString ( ) . c_str ( ) ;
            seek(cStr);
        }
        else if(!QString(name).isEmpty())//根据名字查找
        {

            const char * cStr = name . toStdString ( ) . c_str ( ) ;
            seek(cStr);
        };

        //符合要求的学生信息的输出（不含成绩
        /*
        for(int i=0;i<back_end_data::seek_num;i++)
        {
            QString a;
            a+="编号";
            a+=QString::number(i+1);
            a+=" ";

            a+=back_end_data::seek_res[i]->get_id();
            a+=" ";
            a+=back_end_data::seek_res[i]->get_name();
            a+=" ";

            switch(back_end_data::seek_res[i]->get_sex())
            {
            case 0:
                a+="男";
                a+=" ";
                break;
            case 1:
                a+="女";
                a+=" ";
                break;
            default:
                break;
            }
            switch(back_end_data::seek_res[i]->get_school())
            {//enum school {JI_RUAN, DIAN_XIN, SHU_TONG};
            case 0:
                a+="计算机与软件学院";
                a+=" ";
                break;
            case 1:
                a+="电子与信息技术学院";
                a+=" ";
                break;
            case 2:
                a+="数学与统计学院";
                a+=" ";
                break;
            default:
                break;
            }

            a+=QString::number(back_end_data::seek_res[i]->get_class_num());
            a+="班 ";
            a+="总分：";
            a+=QString::number( back_end_data::seek_res[i]->get_total_score());

            ui->textBrowser->append(a);

        }
*/
        if(back_end_data::seek_num==0)
        {
            QMessageBox::about(this,"提示","没有该学生记录");
        }

//qDebug()<<back_end_data::seek_num;
        //关于成绩的信息输出！！！！！！！！！！！！！！！！！！！！！一个坑未填！！！！！！！！！！！！
        if((!number.isEmpty()||!name.isEmpty())&&back_end_data::seek_num>0)//两个只要有一个不空
        {

                ui->textBrowser->setText("");//清空

                for(int i=0;i<back_end_data::seek_num;i++)
                {
                    QString a,b;
                    b+="编号";
                    b+=QString::number(i+1);
                    b+=" ";

                    b+=back_end_data::seek_res[i]->get_id();
                    b+=" ";
                    b+=back_end_data::seek_res[i]->get_name();
                    b+=" ";

                    switch(back_end_data::seek_res[i]->get_sex())
                    {
                    case 0:
                        b+="男";
                        b+=" ";
                        break;
                    case 1:
                        b+="女";
                        b+=" ";
                        break;
                    default:
                        break;
                    }
                    switch(back_end_data::seek_res[i]->get_school())
                    {//enum school {JI_RUAN, DIAN_XIN, SHU_TONG};
                    case 0:
                        b+="计算机与软件学院";
                        b+=" ";
                        break;
                    case 1:
                        b+="电子与信息技术学院";
                        b+=" ";
                        break;
                    case 2:
                        b+="数学与统计学院";
                        b+=" ";
                        break;
                    default:
                        break;
                    }

                    b+=QString::number(back_end_data::seek_res[i]->get_class_num());
                    b+="班 ";
                    b+="总分：";
                    b+=QString::number( back_end_data::seek_res[i]->get_total_score());

                    ui->textBrowser->append(b);//输出五项基本信息
                    //成绩输出改良版
                    for(int j=0;j<10;j++)
                    {

                        switch(j)
                        {
                        case 0:
                            a+="高数 ";
                            break;
                        case 1:
                            a+="线代 ";
                            break;
                        case 2:
                            a+="程序 ";
                            break;
                        case 3:
                            a+="概统 ";
                            break;
                        case 4:
                            a+="电子 ";
                            break;
                        case 5:
                            a+="近世 ";
                            break;
                        case 6:
                            a+="常微分 ";
                            break;
                        case 7:
                            a+="信号 ";
                            break;
                        case 8:
                            a+="操作系统 ";
                            break;
                        case 9:
                            a+="计网 ";
                            break;
                        default:
                            break;

                        }
                                        qDebug()<<back_end_data::seek_res[i]->get_score(j);
                        if(back_end_data::seek_res[i]->get_score(j)>=0
                                &&back_end_data::seek_res[i]->get_score(j)<=100)
                        {
                            a+=QString::number( back_end_data::seek_res[i]->get_score(j));
                            a+=" ";
                        }
                        else a+="空 ";
                    }

                    ui->textBrowser->append(a);
                    ui->textBrowser->append(" ");
                }


        }
        else
            if(number.isEmpty()&&name.isEmpty())
                QMessageBox::about(this,"ERROR","学号和姓名不能都为空");






    });
//pushbutton_modify
    connect(ui->pushButton_modify,QPushButton::clicked,[=](){
        int bianhao_flag=1;
        if(back_end_data::seek_num==0)
        {
            QMessageBox::about(this,"提示","没有该学生记录");
        }
        else if(back_end_data::seek_num==1)
        {
            s=back_end_data::seek_res[0];
        }

        else
        {
            int num=ui->del_num->text().toInt();
            if(num>=1&&num<=back_end_data::seek_num)
            {
                s=back_end_data::seek_res[num-1];
            }
            else
            {
                QMessageBox::about(this,"error","编号非法");
                bianhao_flag=0;
            }
//            ui->del_num->setText("输入你想操作的学生编号");
        }

        if(back_end_data::seek_num>0&&bianhao_flag)
        {
            ui->textBrowser->setText("");
            //获取指针后 回到修改页面
            ui->stackedWidget->setCurrentWidget(ui->add);
            //五项基本信息的显示
            MainWindow::five_info_show(s);

            //成绩信息的显示
            //先全部清空
            ui->lineEdit_gaoshu->setText("");
            ui->lineEdit_xiandai->setText("");
            ui->lineEdit_chengxu->setText("");
            ui->lineEdit_gaitong->setText("");
            ui->lineEdit_dianzi->setText("");
            ui->lineEdit_jinshi->setText("");
            ui->lineEdit_cwf->setText("");
            ui->lineEdit_os->setText("");
            ui->lineEdit_wangluo->setText("");
            for(int i=0;i<10;i++)
            {
                if(s->get_score(i)>=0&&s->get_score(i)<=100)
                {
                    int score=s->get_score(i);
                    switch(i)
                    {
                    case 0:
                        ui->lineEdit_gaoshu->setText(QString::number(score));
                        break;
                    case 1:
                        ui->lineEdit_xiandai->setText(QString::number(score));
                        break;
                    case 2:
                        ui->lineEdit_chengxu->setText(QString::number(score));
                        break;
                    case 3:
                        ui->lineEdit_gaitong->setText(QString::number(score));
                        break;
                    case 4:
                        ui->lineEdit_dianzi->setText(QString::number(score));
                        break;
                    case 5:
                        ui->lineEdit_jinshi->setText(QString::number(score));
                        break;
                    case 6:
                        ui->lineEdit_cwf->setText(QString::number(score));
                        break;
                    case 7:
                        ui->lineEdit_xinhao->setText(QString::number(score));
                        break;
                    case 8:
                        ui->lineEdit_os->setText(QString::number(score));
                        break;
                    case 9:
                        ui->lineEdit_wangluo->setText(QString::number(score));
                        break;
                    default:
                        break;

                    }

                }
            }

        }

    });
//pushbutton_delete
    connect(ui->pushButton_delete,QPushButton::clicked,[=](){
        int bianhao_flag=1;
        qDebug()<<back_end_data::seek_num;
        if(back_end_data::seek_num==0)
            QMessageBox::about(this,"提示","没有该学生信息");
        else if(back_end_data::seek_num==1)
            del(back_end_data::seek_res[0]);
        else
        {
            int aaaa=ui->del_num->text().toInt();
            if(aaaa>=1&&aaaa<=back_end_data::seek_num)
            {//编号合法
                del(back_end_data::seek_res[aaaa-1]);
                QMessageBox::about(this,"删除","已删除");
            }
            else
            {bianhao_flag=0;
                QMessageBox::about(this,"error","编号非法");
            }
//            qDebug()<<"shuruxuehao";
//            ui->del_num->setText("输入你想操作的学生编号");
        }


        if(bianhao_flag)
        {
            ui->textBrowser->setText("");

            QString number= ui->number_2->text();
            QString name=ui->name_2->text();
            if(!QString(number).isEmpty())//根据学号查找
            {

                const char * cStr = number . toStdString ( ) . c_str ( ) ;
                seek(cStr);
            }
            else if(!QString(name).isEmpty())//根据名字查找
            {

                const char * cStr = name . toStdString ( ) . c_str ( ) ;
                seek(cStr);
            };

            //符合要求的学生信息的输出（不含成绩
            /*
            for(int i=0;i<back_end_data::seek_num;i++)
            {
                QString a;
                a+="编号";
                a+=QString::number(i+1);
                a+=" ";

                a+=back_end_data::seek_res[i]->get_id();
                a+=" ";
                a+=back_end_data::seek_res[i]->get_name();
                a+=" ";

                switch(back_end_data::seek_res[i]->get_sex())
                {
                case 0:
                    a+="男";
                    a+=" ";
                    break;
                case 1:
                    a+="女";
                    a+=" ";
                    break;
                default:
                    break;
                }
                switch(back_end_data::seek_res[i]->get_school())
                {//enum school {JI_RUAN, DIAN_XIN, SHU_TONG};
                case 0:
                    a+="计软";
                    a+=" ";
                    break;
                case 1:
                    a+="电信";
                    a+=" ";
                    break;
                case 2:
                    a+="数统";
                    a+=" ";
                    break;
                default:
                    break;
                }

                a+=QString::number(back_end_data::seek_res[i]->get_class_num());
                a+="班 ";
                a+="总分：";
                a+=QString::number( back_end_data::seek_res[i]->get_total_score());

                ui->textBrowser->append(a);

            }

*/

            //关于成绩的信息输出！！！！！！！！！！！！！！！！！！！！！一个坑未填！！！！！！！！！！！！
            if((!number.isEmpty()||!name.isEmpty())&&back_end_data::seek_num>0)//两个只要有一个不空
            {

                    ui->textBrowser->setText("");//清空

                    for(int i=0;i<back_end_data::seek_num;i++)
                    {
                        QString a,b;
                        b+="编号";
                        b+=QString::number(i+1);
                        b+=" ";

                        b+=back_end_data::seek_res[i]->get_id();
                        b+=" ";
                        b+=back_end_data::seek_res[i]->get_name();
                        b+=" ";

                        switch(back_end_data::seek_res[i]->get_sex())
                        {
                        case 0:
                            b+="男";
                            b+=" ";
                            break;
                        case 1:
                            b+="女";
                            b+=" ";
                            break;
                        default:
                            break;
                        }
                        switch(back_end_data::seek_res[i]->get_school())
                        {//enum school {JI_RUAN, DIAN_XIN, SHU_TONG};
                        case 0:
                            b+="计软";
                            b+=" ";
                            break;
                        case 1:
                            a+="电信";
                            a+=" ";
                            break;
                        case 2:
                            b+="数统";
                            b+=" ";
                            break;
                        default:
                            break;
                        }

                        b+=QString::number(back_end_data::seek_res[i]->get_class_num());
                        b+="班";
                        b+="总分：";
                        b+=QString::number( back_end_data::seek_res[i]->get_total_score());

                        ui->textBrowser->append(b);//输出五项基本信息

                        for(int j=0;j<10;j++)
                        {

                            switch(j)
                            {
                            case 0:
                                a+="高数 ";
                                break;
                            case 1:
                                a+="线代 ";
                                break;
                            case 2:
                                a+="程序 ";
                                break;
                            case 3:
                                a+="概统 ";
                                break;
                            case 4:
                                a+="电子 ";
                                break;
                            case 5:
                                a+="近世 ";
                                break;
                            case 6:
                                a+="常微分 ";
                                break;
                            case 7:
                                a+="信号 ";
                                break;
                            case 8:
                                a+="操作系统 ";
                                break;
                            case 9:
                                a+="网络 ";
                                break;
                            default:
                                break;

                            }
                                            qDebug()<<back_end_data::seek_res[i]->get_score(j);
                            if(back_end_data::seek_res[i]->get_score(j)>=0
                                    &&back_end_data::seek_res[i]->get_score(j)<=100)
                            {
                                a+=QString::number( back_end_data::seek_res[i]->get_score(j));
                                a+=" ";
                            }
                            else a+="空 ";
                        }
                        ui->textBrowser->append(a);
                        ui->textBrowser->append(" ");
                    }



            }


    }});


//pushbutton_delete_all
//    connect(ui->del_all,QPushButton::clicked,[=](){
//        ui->textBrowser->setText("");//清屏
//        ui->number_2->setText("");
//        ui->name_2->setText("");
//        int res=QMessageBox::question(this,"危险操作","你确定要清空数据吗");
//        switch (res)
//        {
//        case QMessageBox::Yes:
//            del_all();
//            QMessageBox::about(this,"删除","已删除");
//            break;
//        case QMessageBox::No:
//            break;
//        default:
//            break;
//        }

//    });

/********************************SORT*********************************************************/
//all_school_sort 总分学院排序
    connect(ui->all_school,QPushButton::clicked,[=](){
        QString major=ui->combo_major_2->currentText();
        const char * cStr = major . toStdString ( ) . c_str ( ) ;
        if(major.isEmpty())
            QMessageBox::about(this,"","学院不能为空");
        else
        {
            sort_by_total_score( cStr);
            ui->sort_show->setText("");//清屏
            cout_stu_info();//输出

        }
    });

//all_class_sort 总分班级排序
    connect(ui->all_class,QPushButton::clicked,[=](){
        QString major=ui->combo_major_2->currentText();
        int class_2=ui->lineEdit_class->text().toInt();
        if(major.isEmpty()||ui->lineEdit_class->text().isEmpty())
            QMessageBox::about(this,"","学院和班级不能为空");
        else
        {
            if(class_2>0)
            {
                const char * cStr = major . toStdString ( ) . c_str ( ) ;
                sort_by_total_score(cStr,class_2);
                ui->sort_show->setText("");//清屏

                cout_stu_info();

            }
            else
                QMessageBox::about(this,"error","班级错误");
        }
    });

//sort_by_single_subject_score_school 单科学院
    connect(ui->subject_school,QPushButton::clicked,[=](){
        MainWindow::check_subject();
        QString major=ui->combo_major_2->currentText();
        QString subject=ui->lineEdit_subject->text();
        if(major.isEmpty()||subject.isEmpty());
            //QMessageBox::about(this,"","学院和学科不能为空");
        else
        {
            QString subject=ui->lineEdit_subject->text();
            const char * cStr1 = major . toStdString ( ) . c_str ( ) ;
            const char * cStr2 = subject . toStdString ( ) . c_str ( ) ;

            sort_by_subject_score(cStr1,cStr2);
            ui->sort_show->setText("");//清屏

            cout_stu_info();

        }
    });

//sort_by_single_subject_score_class 单科班级
    connect(ui->subject_class,QPushButton::clicked,[=](){
        MainWindow::check_subject();
        QString major=ui->combo_major_2->currentText();
        QString subject=ui->lineEdit_subject->text();
//        qDebug()<< ui->lineEdit_class->text().isEmpty();

        if(major.isEmpty()||subject.isEmpty()||ui->lineEdit_class->text().isEmpty());
            //QMessageBox::about(this,"","学院学科班级不能为空");
        else
        {
            QString subject=ui->lineEdit_subject->text();
            int class_2=ui->lineEdit_class->text().toInt();
            if(class_2>0)
            {
                const char * cStr1 = major . toStdString ( ) . c_str ( ) ;
                const char * cStr2 = subject . toStdString ( ) . c_str ( ) ;


                sort_by_subject_score(cStr1,class_2,cStr2);
                ui->sort_show->setText("");//清屏

                cout_stu_info();

            }
            else
                QMessageBox::about(this,"error","班级错误");
        }
    });
//sort_by_id_school
    connect(ui->sort_by_id_school,QPushButton::clicked,[=](){
        sort_by_id();//按学校排序
        ui->sort_show->setText("");//清屏

        cout_stu_info();
    });
//sort_by_id_xueyuan
        connect(ui->sort_by_id_xueyuan,QPushButton::clicked,[=](){
            QString major=ui->combo_major_2->currentText();
            if(major.isEmpty())
                QMessageBox::about(this,"","学院不能为空");
            else
            {
                const char * cStr1 = major . toStdString ( ) . c_str ( ) ;

                sort_by_id(cStr1);
                ui->sort_show->setText("");//清屏

                cout_stu_info();

            }
        });
//sort_by_id_class
            connect(ui->sort_by_id_class,QPushButton::clicked,[=](){
                QString major=ui->combo_major_2->currentText();
                int class_2=ui->lineEdit_class->text().toInt();
                if(major.isEmpty()||ui->lineEdit_class->text().isEmpty())
                    QMessageBox::about(this,"","学院班级不能为空");
                else
                {
                    if(class_2>0)
                    {
                        const char * cStr = major . toStdString ( ) . c_str ( ) ;

                        sort_by_id(cStr,class_2);
                        ui->sort_show->setText("");//清屏

                        cout_stu_info();

                    }
                    else
                        QMessageBox::about(this,"error","班级错误");
                }
            });

/*-------------------------其他---------------------------------------------------*/

//通过率全校
            connect(ui->pass_school,QPushButton::clicked,[=](){
                QString subject=ui->lineEdit_subject->text();
                if(subject.isEmpty())
                    QMessageBox::about(this,"","学科不能为空");
                else
                {
                    MainWindow::check_subject();
                    QString subject=ui->lineEdit_subject->text();
                    const char * cStr = subject . toStdString ( ) . c_str ( ) ;

                    QString a="全校通过率";
                    a+=QString::number(subject_pass_rate(cStr), 10, 2);
                    ui->sort_show->setText("");
                    ui->sort_show->append(a);

                }
            }) ;

//通过率 院
            connect(ui->pass_major,QPushButton::clicked,[=](){
                QString major=ui->combo_major_2->currentText();
                QString subject=ui->lineEdit_subject->text();
                if(major.isEmpty()||subject.isEmpty())
                    QMessageBox::about(this,"","学院学科不能为空");
                else
                {
                    MainWindow::check_subject();
                    QString subject=ui->lineEdit_subject->text();
                    const char * cStr1 = major . toStdString ( ) . c_str ( ) ;
                    const char * cStr2 = subject . toStdString ( ) . c_str ( ) ;

                    QString a="院通过率";
                    a+=QString::number(subject_pass_rate(cStr1,cStr2), 10, 2);
                    ui->sort_show->setText("");

                    ui->sort_show->append(a);

                }

            })  ;

//通过率 班级
            connect(ui->pass_class,QPushButton::clicked,[=](){
                QString major=ui->combo_major_2->currentText();
                QString subject=ui->lineEdit_subject->text();
                if(major.isEmpty()||subject.isEmpty()||ui->lineEdit_class->text().isEmpty())
                    QMessageBox::about(this,"","学院学科班级不能为空");
                else
                {
                    MainWindow::check_subject();
                    QString subject=ui->lineEdit_subject->text();
                    int class_2=ui->lineEdit_class->text().toInt();
                    qDebug()<<class_2;
                    if(class_2>0)
                    {
                        const char * cStr1 = major . toStdString ( ) . c_str ( ) ;
                        const char * cStr2 = subject . toStdString ( ) . c_str ( ) ;

                        QString a="班级通过率";
                        a+=QString::number(subject_pass_rate(cStr1,class_2,cStr2), 10, 2);
                        ui->sort_show->setText("");

                        ui->sort_show->append(a);

                    }
                    else
                        QMessageBox::about(this,"error","班级错误");
                }
            })  ;


//平均分全校
            connect(ui->average_school,QPushButton::clicked,[=](){
                QString subject=ui->lineEdit_subject->text();
                if(subject.isEmpty())
                    QMessageBox::about(this,"","学科不能为空");
                else
                {
                    MainWindow::check_subject();
                    QString subject=ui->lineEdit_subject->text();
                    const char * cStr = subject . toStdString ( ) . c_str ( ) ;

                    QString a="全校平均分";
                    a+=QString::number(subject_average(cStr), 10, 2);
                    ui->sort_show->setText("");

                    ui->sort_show->append(a);

                }
            }) ;

//平均分 院
            connect(ui->average_major,QPushButton::clicked,[=](){
                QString major=ui->combo_major_2->currentText();
                QString subject=ui->lineEdit_subject->text();
                if(major.isEmpty()||subject.isEmpty())
                    QMessageBox::about(this,"","学院学科不能为空");

                else
                {
                    MainWindow::check_subject();
                    QString subject=ui->lineEdit_subject->text();
                    const char * cStr1 = major . toStdString ( ) . c_str ( ) ;
                    const char * cStr2 = subject . toStdString ( ) . c_str ( ) ;

                    QString a="院平均分";
                    a+=QString::number(subject_average(cStr1,cStr2), 10, 2);
                    ui->sort_show->setText("");

                    ui->sort_show->append(a);

                }


            })  ;

//平均分 班级
            connect(ui->average_class,QPushButton::clicked,[=](){
                QString major=ui->combo_major_2->currentText();
                QString subject=ui->lineEdit_subject->text();
                if(major.isEmpty()||subject.isEmpty()||ui->lineEdit_class->text().isEmpty())
                    QMessageBox::about(this,"","学院学科班级不能为空");

                else
                {
                    MainWindow::check_subject();
                    QString subject=ui->lineEdit_subject->text();
                    int class_2=ui->lineEdit_class->text().toInt();
                    if(class_2>0)
                    {
                        const char * cStr1 = major . toStdString ( ) . c_str ( ) ;
                        const char * cStr2 = subject . toStdString ( ) . c_str ( ) ;

                        QString a="班级平均分";
                        a+=QString::number(subject_average(cStr1,class_2,cStr2), 10, 2);
                        ui->sort_show->setText("");

                        ui->sort_show->append(a);

                    }
                    else
                        QMessageBox::about(this,"error","班级错误");
                }
            })  ;



}


void MainWindow::sub_close()
{
    ui->label_chengxu->close();
    ui->lineEdit_chengxu->close();
    ui->label_cwf->close();
    ui->lineEdit_cwf->close();
    ui->label_dianzi->close();
    ui->lineEdit_dianzi->close();
    ui->label_gaitong->close();
    ui->lineEdit_gaitong->close();
    ui->label_jinshi->close();
    ui->lineEdit_jinshi->close();
    ui->label_gaoshu->close();
    ui->lineEdit_gaoshu->close();
    ui->label_xiandai->close();
    ui->lineEdit_xiandai->close();
    ui->label_os->close();
    ui->lineEdit_os->close();
    ui->label_xinhao->close();
    ui->lineEdit_xinhao->close();
    ui->label_wangluo->close();
    ui->lineEdit_wangluo->close();

}

void MainWindow::seek_output()
{
//    for(int i=0;i</*seek_num*/;i++)
//    {
//        ui->textBrowser->append(/*QString[i]*/);
//    };
}

MainWindow::~MainWindow()
{
    delete ui;
}


/************************PAGECHANGE******************************************************************/
//切换添加界面
void MainWindow::on_action_add_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->add);
}
//切换查询界面
void MainWindow::on_action_search_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->search);
//    ui->del_num->setText("请输入要操作学生的编号");
}
//切换排序界面
void MainWindow::on_action_sort_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->sort);
}



//删除操作
void MainWindow::on_pushButton_delete_clicked()
{

}

//输入检错
int MainWindow:: check_input_mistake()
{

    QString number= ui->number->text();
    QString name=ui->name->text();
    QString sex=ui->sex->currentText();
    QString major=ui->combo_major->currentText();
    int class_2=ui->class_2->text().toInt();

    //学号检错
//    if(number.size()>14)
//    {
//        QMessageBox::about(this,"ERROR","学号过长");
//        return 0;//error
//    }
    //名字检错
//    if(name.size()>10)
//    {
//        QMessageBox::about(this,"ERROR","名字过长");
//        return 0;
//    }


    //院系检错
//    if(QString::compare(major,"计软")&&
//            QString::compare(major,"电信")&&
//            QString::compare(major,"数统")&&
//            QString::compare(major,"")
//            )

//    {
//        QMessageBox::about(this,"ERROR","院系错误");
//        return 0;
//    }

    //空串判错
    if(number.isEmpty()||name.isEmpty()||sex.isEmpty()
            ||ui->class_2->text().isEmpty())
    {
        QMessageBox::about(this,"ERROR","学号姓名班级不能为空");
        return 0;
    }

    return 1;//正常
}

//成绩检错
int MainWindow::score(int a)
{
    if(a==-1||a==-2||(a>=0&&a<=100))
        return 1;
    else return 0;
}
int MainWindow::check_score()
{
    int score_gaoshu=ui->lineEdit_gaoshu->text().toInt();
    int score_xiandai=ui->lineEdit_xiandai->text().toInt();
    int score_chengxu=ui->lineEdit_chengxu->text().toInt();
    int score_gaitong=ui->lineEdit_gaitong->text().toInt();
    int score_dianzi=ui->lineEdit_dianzi->text().toInt();
    int score_jinshi=ui->lineEdit_jinshi->text().toInt();
    int score_cwf=ui->lineEdit_cwf->text().toInt();
    int score_xinhao=ui->lineEdit_xinhao->text().toInt();
    int score_os=ui->lineEdit_os->text().toInt();
    int score_wangluo=ui->lineEdit_wangluo->text().toInt();
    if(
            !(MainWindow::score(score_gaoshu)&&
            MainWindow::score(score_xiandai)&&
            MainWindow::score(score_chengxu)&&
            MainWindow::score(score_gaitong)&&
            MainWindow::score(score_dianzi)&&
            MainWindow::score(score_jinshi)&&
            MainWindow::score(score_cwf)&&
            MainWindow::score(score_xinhao)&&
            MainWindow::score(score_os)&&
            MainWindow::score(score_wangluo))

            )
    {
        QMessageBox::about(this,"ERROR","成绩错误");
        return 0;//错误
    }
    else return 1;
}

//学科类型检错
void MainWindow::check_subject()
{
    QString subject=ui->lineEdit_subject->text();
    if(
            QString::compare(subject,"高数")&&
            QString::compare(subject,"现代")&&
            QString::compare(subject,"程序")&&
            QString::compare(subject,"电子")&&
            QString::compare(subject,"概统")&&
            QString::compare(subject,"近世")&&
            QString::compare(subject,"常微分")&&
            QString::compare(subject,"信号")&&
            QString::compare(subject,"操作系统")&&
            QString::compare(subject,"网络")&&
            QString::compare(subject,"")&&
            QString::compare(subject,"输入查询的学科")
            )

        QMessageBox::about(this,"ERROR","输入学科错误");

    if(!QString::compare(subject,"")||!QString::compare(subject,"输入查询的学科"))
        QMessageBox::about(this,"ERROR","请输入学科");

}


void MainWindow::on_action_save_triggered()
{
    save();
}

void MainWindow:: cout_stu_info()
{
    ui->sort_show->setText("");
    for(int i=0;i<back_end_data::seek_num;i++)
    {
        QString a;
        a+="编号";
        a+=QString::number(i+1);
        a+=" ";
        a+=back_end_data::seek_res[i]->get_id();
        a+=" ";
        a+=back_end_data::seek_res[i]->get_name();
        a+=" ";

        switch(back_end_data::seek_res[i]->get_sex())
        {
        case 0:
            a+="男";
            a+=" ";
            break;
        case 1:
            a+="女";
            a+=" ";
            break;
        default:
            break;
        }
        switch(back_end_data::seek_res[i]->get_school())
        {//enum school {JI_RUAN, DIAN_XIN, SHU_TONG};
        case 0:
            a+="计算机与软件学院";
            a+=" ";
            break;
        case 1:
            a+="电子与信息技术学院";
            a+=" ";
            break;
        case 2:
            a+="数学与统计学院";
            a+=" ";
            break;
        default:
            break;
        }

        a+=QString::number(back_end_data::seek_res[i]->get_class_num());
        a+="班 ";
        if(total_score_flag==1)
        {
            a+="总分：";
            a+=QString::number( back_end_data::seek_res[i]->get_total_score());
        }
        ui->sort_show->append(a);


        a.clear();
        //成绩输出改良版
        for(int j=0;j<10;j++)
        {

            switch(j)
            {
            case 0:
                a+="高数 ";
                break;
            case 1:
                a+="线代 ";
                break;
            case 2:
                a+="程序 ";
                break;
            case 3:
                a+="概统 ";
                break;
            case 4:
                a+="电子 ";
                break;
            case 5:
                a+="近世 ";
                break;
            case 6:
                a+="常微分 ";
                break;
            case 7:
                a+="信号 ";
                break;
            case 8:
                a+="操作系统 ";
                break;
            case 9:
                a+="计网 ";
                break;
            default:
                break;

            }
            if(back_end_data::seek_res[i]->get_score(j)>=0
                    &&back_end_data::seek_res[i]->get_score(j)<=100)
            {
                a+=QString::number( back_end_data::seek_res[i]->get_score(j));
                a+=" ";
            }
            else a+="空 ";
        }
        ui->sort_show->append(a);
QApplication::processEvents();
        ui->sort_show->append("");
    }

}

//sleep函数
void MainWindow::sleep(unsigned int msec)
{
    QTime reachtime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachtime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
//成绩判空,若空，返回-5，不空，返回成绩整数
int MainWindow::score_empty(QString score)
{
    if(score.isEmpty())return -5;//成绩为空 无效
    else
    {
        int a=score.toInt();
        return a;
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->add);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->search);
//    ui->del_num->setText("请输入要操作的学生编号");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sort);

}

void MainWindow::on_pushButton_4_clicked()
{
    save();
    QMessageBox::about(this,"","已保存");
}

void MainWindow::on_action_mainmenu_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->else_2);

}

//五项基本信息输出，仅用于modify的显示
void MainWindow::five_info_show(student *s)
{
    QString number(s->get_id());
    QString name(s->get_name());
    QString major(s->get_school_string());
    int sex=s->get_sex();
    QString class_num=QString::number(s->get_class_num());
    ui->number->setText(number);
    ui->name->setText(name);
    ui->sex->setCurrentIndex(sex);
    ui->class_2->setText(class_num);
    int major1=s->get_school();
    ui->combo_major->setCurrentIndex(major1);
}

void MainWindow::on_back_to_menu_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->else_2);

}

void MainWindow::on_back_to_menu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->else_2);

}

void MainWindow::on_back_to_menu_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->else_2);

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->setText("");//清屏
    ui->number_2->setText("");
    ui->name_2->setText("");
    int res=QMessageBox::question(this,"危险操作","你确定要清空数据吗");
    switch (res)
    {
    case QMessageBox::Yes:
        del_all();
        QMessageBox::about(this,"删除","已删除");
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }

}

void MainWindow::on_exit_clicked()
{
    exit(0);
}
