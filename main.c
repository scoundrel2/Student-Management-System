#include"student.h"
#define time 40

void menu()
{
	kuang();
	goto_xy(50, 1);
	printf("�� ");
	Sleep(time);
	printf("ӭ ");
	Sleep(time);
	printf("ʹ ");
	Sleep(time);
	printf("�� ");
	Sleep(time);
	printf("ѧ ");
	Sleep(time);
	printf("�� ");
	Sleep(time);
	printf("�� ");
	Sleep(time);
	printf("�� ");
	Sleep(time);
	printf("ϵ ");
	Sleep(time);
	printf("ͳ");
	goto_xy(57, 6);
	printf("1.ѧ  ��  ע  ��");
	goto_xy(57, 7);
	printf("2.ѧ  ��  ��  ¼");
	goto_xy(57, 8);
	printf("3.��  ʦ  ע  ��");
	goto_xy(57, 9);
	printf("4.��  ʦ  ��  ¼");
	goto_xy(57, 10);
	printf("5.�� �� Ա �� ¼");
	goto_xy(57, 15);
	printf("0.��          ��");
	printf("\n\n\n\n\n\n");
}
//�˵���
void firstselect()
{
	
	Account *pHead = NULL;
	char a[100];
	do {
		system("cls");
		menu();
		goto_xy(50, 12);
		printf("����������ѡ��");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead = Readstudate();
			pHead = register_stu(pHead);
			Save_register_stu(pHead);
			Sleep(1000);
		}
		else if (strcmp("2", a) == 0)
		{

			Login_stu();
			getch();
		}
		else if (strcmp("3", a) == 0)
		{
			pHead = Readteadate();
			pHead = register_tea(pHead);
			Save_register_tea(pHead);
			Sleep(1000);
		}
		else if (strcmp("4", a) == 0)
		{
			Login_tea();
			getch();
		}
		else if (strcmp("5", a) == 0)
		{
			char *p;
			p = Read_manps();
			Login_man(p);
			man_select();
		}
		else if (strcmp("0", a) == 0)
		{
			system("cls");
			goto_xy(50, 10);
			printf("�����˳�ϵͳ��");
			Exit();
			system("cls");
			exit(1);
		}
		else
		{
			goto_xy(50, 13);
			printf("����������������룡");
			Sleep(1000);
		}
	} while (strcmp(a, "0"));

}
//һ���˵�
int main(void)
{
	firstselect();
}