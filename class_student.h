#include<iostream>
#include<cstdio>
using namespace std;

enum school {����Ժ, ����Ժ, ��ͳԺ};
enum sex {��, Ů};
enum subject_name {�ߵ���ѧ, ���Դ���, ������ƻ���, ����ͳ��, ���Ӽ�������, ��������, ��΢�ַ���, �ź���ϵͳ, ����ϵͳ, ���������};

class student
{
public:
    student(const char*, const char*, int, int, int);
    char* get_id();
    char* get_name();
    int get_sex();
    int get_school();
    int get_class_num();
    int get_score(int);
    void modify_school(int);
    void modify_class_num();
    void modify_score(int, int);
protected:
    char id[15];
    char name[20];
    int stu_sex;
    int stu_school;
    int class_num;
    int score[20];//-1��˼Ϊδѡ�Σ�-2��˼Ϊѡ�ε��ǻ�û�п��ԣ�0~100��˼Ϊѡ�����гɼ�
    int total_score;
};