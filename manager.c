#include"student.h"

void Login_man_menu()
{

	system("cls");
	kuang();
	goto_xy(55, 1);
	printf("��   ��   Ա   ��    ¼");
	goto_xy(57, 6);
	printf("�˻�����Manager");
	goto_xy(57, 8);
	printf("��  �룺");

	printf("\n\n\n\n\n");

}
//����Ա��¼����
void second_manger()
{
	system("cls");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ��                     �� �� Ա ��                        ��\n");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ��                   1.�޸�ѧ������                       ��\n");
	printf("				 ��                   2.�޸Ľ�ʦ����                       ��\n");
	printf("				 ��                   3.ɾ��ѧ��ע����Ϣ                   ��\n");
	printf("				 ��                   4.ɾ����ʦע����Ϣ                   ��\n");
	printf("				 ��                   5.��ѯѧ���˻���Ϣ                   ��\n");
	printf("				 ��                   6.��ѯ��ʦ�˻���Ϣ                   ��\n");
	printf("				 ��                   7.�޸Ĺ���Ա����                     ��\n");
	printf("				 ��                   8.��ʼ������Ա����                   ��\n");
	printf("				 ��                   9.��  ��  ��  ¼                     ��\n");
	printf("				 ��                   0.��  ��  ϵ  ͳ                     ��\n");
	printf("				 ------------------------------------------------------------\n");
}
//����Ա�����˵�
void Login_man(char * p)
{
	char ch;
	int flag = 1;
	while (flag)
	{
		Login_man_menu();
		goto_xy(65, 8);
		char key[20];
		int i = 0;
		while ((ch = getch()) != '\r')
		{
			if (ch < 0)//�ų��������Ҽ�
			{
				getch();
				continue;
			}
			else if (ch == '\b'&&i>0)
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				i--;
			}
			else if (!isdigit(ch) && !isalpha(ch))
				continue;
			else if (i >= 15)
				continue;
			else
			{
				putchar('*');
				key[i++] = ch;
			}
		}
		key[i] = '\0';

		if (strcmp(p, key) == 0)
		{
			goto_xy(57, 14);
			printf("��½�ɹ���");
			Sleep(1000);
			flag = 0;
		}
		else
		{
			goto_xy(57, 14);
			printf("������������µ�¼��");
			Sleep(1000);
			continue;
		}


	}


}
//����Ա��¼
Account *Read_stureg()
{
	FILE *fp;;
	Account *pHead, *pEnd, *pNew = NULL;

	pHead = (Account *)malloc(sizeof(Account));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("register_stu.txt", "r")) == NULL)
	{
		printf("\t\t\t\t���ļ�ʧ�ܣ�\n");
		getch();
	}
	else
	{
		pNew = (Account*)malloc(sizeof(Account));
		while ((fread(pNew, sizeof(Account), 1, fp))>0)
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
			pNew = (Account*)malloc(sizeof(Account));
		}
	}
	free(pNew);
	fclose(fp);
	return pHead;

}
//��ѧ���˻���Ϣ������
Account *Read_teareg()
{
	FILE *fp;;
	Account *pHead, *pEnd, *pNew = NULL;

	pHead = (Account *)malloc(sizeof(Account));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("register_teacher.txt", "r")) == NULL)
	{
		printf("\t\t\t\t���ļ�ʧ�ܣ�\n");
		getchar();
	}
	else
	{
		pNew = (Account*)malloc(sizeof(Account));
		while ((fread(pNew, sizeof(Account), 1, fp))>0)
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
			pNew = (Account*)malloc(sizeof(Account));
		}
	}
	free(pNew);
	fclose(fp);
	return pHead;

}
//����ʦ�˻���Ϣ������
Account * Modify_reg(Account *pHead)
{
	Account * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t         �����޸�\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t�������û�����");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t�û�������Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->name, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		return 0;
	}
	else
	{
		char psw[15];
		printf("\t\t\t\t�����������룺");
		scanf("%s", psw);
		strcpy(ptemp->password, psw);
		printf("\t\t\t\t�޸ĳɹ���\n");	
	}
	return pHead;
}
//�޸�����
Account *Delete_reg(Account*pHead)
{
	Account * ptemp = pHead, *ptemp1 = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        �û���Ϣɾ��\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t�������û�����");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t�û�������Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->name, n) != 0)
	{
		ptemp1 = ptemp;
		ptemp = ptemp->next;
	}
	if (ptemp == NULL)
	{
		printf("\t\t\t\t�޸��û�����Ϣ��\n");
		return NULL;
	}
	else
	{
		ptemp1->next = ptemp->next;
		free(ptemp);
		printf("\t\t\t\tɾ���ɹ���\n");
	}
	return pHead;
}
//ɾ���˻�������
void *Query_reg(Account*pHead)
{
	Account * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        �˻���Ϣ��ѯ\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t�������û�����");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t�û�������Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->name, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t�޸��û�����Ϣ\n");
		Sleep(1000);
		return 0;
	}
	else
	{
		printf("\t\t\t\t----------------------------\n");
		printf("\t\t\t\t    �û���:%s\n", ptemp->name);
		printf("\t\t\t\t    ��  ��:%s\n", ptemp->password);
		printf("\t\t\t\t----------------------------\n");
	}

}
//��ѯ�˻�������
void Save_reg_stu(Account * pHead)
{
	FILE *fp = NULL;
	Account * pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("�޸��û���Ϣ�������������\n");
		getch();
		return;
	}
	fp = fopen("register_stu.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("�ļ���ʧ�ܣ��������������\n");
		Sleep(1500);
		getch();
	}
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(Account), 1, fp);
		pTemp = pTemp->next;
	}
	printf("\t\t\t\t����ɹ�!\n");
	fflush(fp);
	fclose(fp);
	Sleep(1000);
	fp = NULL;
	return;
}
//�������ݵ�ѧ��ע���ļ�(��д)
void Save_reg_tea(Account * pHead)
{
	FILE *fp = NULL;
	Account * pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("�޸��û���Ϣ�������������\n");
		getch();
		return;
	}
	fp = fopen("register_teacher.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("�ļ���ʧ�ܣ��������������\n");
		Sleep(1500);
		getch();
	}
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(Account), 1, fp);
		pTemp = pTemp->next;
	}
	fflush(fp);
	fclose(fp);
	printf("\t\t\t\t����ɹ�!\n");
	Sleep(1000);
	fp = NULL;
	return;
}
//�������ݵ���ʦע���ļ�(��д)
char * Read_manps()
{
	FILE * fp;
	static char a[20];
	if ((fp = fopen("register_man.txt", "r")) ,fp == NULL)
	{
		printf("\t\t\t\t���ļ�ʧ�ܣ�\n");
		getchar();
	}
	else
	{
		fread(a, sizeof(a), 1, fp);
	}
	fclose(fp);
	return a;
}
//��ȡ����Ա����
void chushi_man()
{
	FILE *fp;
	fp = fopen("register_man.txt", "w+");
	char a[20] = "1234567";
	fwrite(a, sizeof(a), 1, fp);
	fclose(fp);	
}
//����Ա�����ʼ��
void Modify_man()
{
	FILE *fp;
	fp = fopen("register_man.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("�ļ���ʧ�ܣ��������������\n");
		Sleep(1500);
		getch();
	}
	else
	{
		char a[20];
		printf("\t\t\t\t---------------------------\n");
		printf("\t\t\t\t���������Ա�����룺");
		scanf("%s", a);
		printf("\t\t\t\t---------------------------\n");
		fwrite(a, sizeof(a), 1, fp);
		printf("\t\t\t\t�޸ĳɹ���\n");
	}
	fclose(fp);
}
//�޸Ĺ���Ա����
void man_select()
{
	Account *pHead;
	char a[100];
	do {
		system("cls");
		second_manger();
		goto_xy(50, 14);
		printf("����������ѡ��");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead=Read_stureg();
			pHead=Modify_reg(pHead);
			Save_reg_stu(pHead);	
		}
		else if (strcmp("2", a) == 0)
		{
			pHead = Read_teareg();
			pHead = Modify_reg(pHead);
			Save_reg_tea(pHead);
		}
		else if (strcmp("3", a) == 0)
		{
			pHead = Read_stureg();
			pHead = Delete_reg(pHead);
			Save_reg_stu(pHead);
			
		}
		else if (strcmp("4", a) == 0)
		{
			pHead = Read_teareg();
			pHead = Delete_reg(pHead);
			Save_reg_tea(pHead);
		}
		else if (strcmp("5", a) == 0)
		{
			pHead = Read_stureg();
			Query_reg(pHead);
			printf("\t\t\t\t�����밴�����\n");
			getch();
			
		}
		else if (strcmp("6", a) == 0)
		{
			pHead = Read_teareg();
			Query_reg(pHead);
			printf("\t\t\t\t�����밴�����\n");
			getch();
		}
		else if (strcmp("7", a) == 0)
		{
			Modify_man();
			printf("\t\t\t\t�����밴�����\n");
			getch();
		}
		else if (strcmp("8", a) == 0)
		{
			chushi_man();
			printf("\t\t\t\t�����밴�����\n");
			getch();
		}
		else if (strcmp("9", a) == 0)
		{
			firstselect();
		}
		else if (strcmp("0", a) == 0)
		{
			system("cls");
			goto_xy(50, 10);
			printf("�����˳�ϵͳ��");
			Exit();
			Sleep(500);
			system("cls");
			exit(1);
		}
		else
		{
			goto_xy(50, 13);
			printf("����������������룡");
			goto_xy(66, 12);
			printf("              ");
			goto_xy(66, 12);
		}
	} while (strcmp(a, "0"));


}
//����Ա�����˵�