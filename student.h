#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#ifndef STUDENT_H
#define STUDENT_H

struct date
{
	int year;
	int month;
	int day;
};
typedef struct information
{
	char num[9];
	char name[21];
	char sex[6];
	struct date birthday;
	float score[3];
	double sum;

}Node;
typedef struct student
{
	Node node;
	struct student * next;
}List;
typedef struct ACCOUNT
{
	char name[9];
	char password[15];
	struct ACCOUNT * next;

}Account;

Account * register_stu(Account *pHead);//ѧ��ע��
Account * register_tea(Account *pHead);//��ʦע��
int Lookup_stu(char *);//����
int Lookup_tea(char *);//����
char * Getname();//��ȡ�û���
int Matching_stu(char *stunum, char*stupass);//�û���������ƥ��
int Matching_tea(char *stunum, char*stupass);//�û���������ƥ��
int Judge_password(char ch);//�ж������Ƿ����
void goto_xy(int x, int y);//����ƶ�
void kuang();
void login_stu();//ѧ����¼
void second_stu();//ѧ�������˵�
void login_tea();//��ʦ��¼
void second_tea();//��ʦ�����˵�
int judge_no(char num[], int len);//�ж�ѧ�������Ƿ���ȷ
List * Input_stu();//¼��
List * Increase_stu(List * pHead);  //����
List * Delete_stu_bynum(List * pHead);//ɾ��
List * Modify(List *pHead); //�޸�
void  Query(List * pHead);//��ѯ
List * Sort_by_sum(List * pHead);//ѧ����������
List * Sort_by_sum(List * pHead);
int Lookup_stu_date(char *stunum);//ѧ�����ݲ���


#endif
