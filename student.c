#include"student.h"

void second_tea()
{
	system("cls");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ��                     ��  ʦ  ��                         ��\n");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ��                   1.¼��ѧ����Ϣ                       ��\n");
	printf("				 ��                   2.����ѧ����Ϣ                       ��\n");
	printf("				 ��                   3.ɾ��ѧ����Ϣ                       ��\n");
	printf("				 ��                   4.�޸�ѧ����Ϣ                       ��\n");
	printf("				 ��                   5.��ѯѧ����Ϣ                       ��\n");
	printf("				 ��                   6.���ѧ����Ϣ                       ��\n");
	printf("				 ��                   7.�� �� �� ��                        ��\n");
	printf("				 ��                   8.�ⲿ������Ϣ                       ��\n");
	printf("				 ��                   9.�� �� �� ¼                        ��\n");
	printf("				 ��                   0.�� �� ϵ ͳ                        ��\n");
	printf("				 ------------------------------------------------------------\n");
}
//��ʦ�˲˵�
void second_stu()
{
	system("cls");
	printf("\t\t\t\t----------------------------------------------------------------------\n");
	printf("\t\t\t\t��                           ѧ  ��  ��                             �� \n");
	printf("\t\t\t\t----------------------------------------------------------------------\n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                        1.��  Ϣ  ��  ѯ                          �� \n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                        2.��  ��  ��  ��                          �� \n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                        3.��  ��  ��  ¼                          �� \n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                                                                  �� \n");
	printf("\t\t\t\t��                        0.��  ��  ϵ  ͳ                          �� \n");
	printf("\t\t\t\t----------------------------------------------------------------------\n");
}
//ѧ���˲˵�
int Lookup_stu_date(char *stunum)
{
	List *a;
	a = (List*)malloc(sizeof(List));
	FILE *fp;
	fp = fopen("stu_date.txt", "r");
	while (!feof(fp))
	{

		fread(a, sizeof(List), 1, fp);
		if (strcmp(a->node.num,stunum) == 0)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;

}
//ѧ����Ϣѧ�Ų���
List * Input_stu(List*pHead)
{
	float a, b, c;
	int flag = 1;
	List *pNew;
	pNew = (List *)malloc(sizeof(List));
	pNew->next = NULL;
	printf("\t\t\t\t*******************************\n");
	printf("\t\t\t\t        ѧ����Ϣ¼��\n");
	printf("\t\t\t\t*******************************\n");
	printf("\t\t\t\t������ѧ��ѧ�ţ�����0��������");
	scanf("%s", pNew->node.num);
	while (strcmp(pNew->node.num, "0") != 0)
	{
		if (judge_no(pNew->node.num, 8) == 0)
		{
			printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			printf("\t\t\t\t*******************************\n");
			printf("\t\t\t\t        ѧ����Ϣ¼��\n");
			printf("\t\t\t\t*******************************\n");
			printf("\t\t\t\t������ѧ��ѧ�ţ�����0��������");
			scanf("%s", pNew->node.num);
			continue;
		}
		while (1)
		{
			if (Lookup_stu_date(pNew->node.num) == 0)
			{
				break; 
			}
			else
			{
				printf("\t\t\t\t��ѧ���Ѵ��ڣ����������룡\n");
				printf("\t\t\t\t������ѧ����ѧ�ţ�");
				scanf("%s", pNew->node.num);
			}
		}

		printf("\t\t\t\t������ѧ��������");
		scanf("%s", pNew->node.name);
		printf("\t\t\t\t������ѧ���Ա�");
		scanf("%s", &pNew->node.sex);
		printf("\t\t\t\t������ѧ���������ڣ��ո������");
		scanf("%d %d %d", &pNew->node.birthday.year, &pNew->node.birthday.month, &pNew->node.birthday.day);
		while (1)
		{
			printf("\t\t\t\t������ѧ�������ſγɼ����ո������");
			scanf("%f %f %f", &a, &b, &c);
			if (a < 0 || b < 0 || c < 0)
				printf("\t\t\t\t������Ϣ��������������!\n");
			else
			{
				pNew->node.score[0] = a;
				pNew->node.score[1] = b;
				pNew->node.score[2] = c;
				break;
			}
		}
		pNew->node.sum = pNew->node.score[0] + pNew->node.score[1] + pNew->node.score[2];//�����ܳɼ�

		pNew->next = pHead->next;
		pHead->next = pNew;

		pNew = (List *)malloc(sizeof(List));
		printf("\n");
		printf("\t\t\t\t������ѧ��(����0����)��");
		scanf("%s", pNew->node.num);
	}
	free(pNew);
	return pHead;
}
//¼��
List *  Increase_stu(List * pHead)
{
	List * ptemp = pHead, *pNew;
	float a, b, c;
	char n[9];
	int flag = 1;
	while (flag)
	{
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        ѧ����Ϣ����\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t������Ҫ���ӵ���λͬѧ��");
		scanf("%s", n);
	
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			continue;
		}
		while (ptemp&&strcmp(ptemp->node.num, n) != 0)
			ptemp = ptemp->next;
		if (ptemp == NULL)
		{
			printf("\t\t\t\t�޸�ѧ����������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;


		pNew = (List*)malloc(sizeof(List));
		printf("\t\t\t\t���������ѧ����ѧ��(������0)��");
		scanf("%s", pNew->node.num);
		while (strcmp(pNew->node.num, "0") != 0)
		{
				if (judge_no(n, 8) == 0)
				{
					printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
					Sleep(1000);
					system("cls");
					continue;
				}
				while (1)
				{
					if ((Lookup_stu_date(pNew->node.num)) == 0)
					{
						
						break;
					}
					else
					{
						printf("\t\t\t\t��ѧ���Ѵ��ڣ����������룡\n");
						printf("\t\t\t\t���������ѧ����ѧ�ţ�");
						scanf_s("%s", pNew->node.num, 9);
					}
				}
				printf("\t\t\t\t������ѧ��������");
				scanf("%s", pNew->node.name);
				printf("\t\t\t\t������ѧ���Ա�");
				scanf("%s", &pNew->node.sex);
				printf("\t\t\t\t������ѧ���������ڣ��ո������");
				scanf("%d %d %d", &pNew->node.birthday.year, &pNew->node.birthday.month, &pNew->node.birthday.day);
				while (1)
				{
					printf("\t\t\t\t������ѧ�������ſγɼ����ո������");
					scanf("%f %f %f", &a, &b, &c);
					if (a < 0 || b < 0 || c < 0)
						printf("\t\t\t\t������Ϣ��������������!\n");
					else
					{
						pNew->node.score[0] = a;
						pNew->node.score[1] = b;
						pNew->node.score[2] = c;
						break;
					}
				}
				pNew->node.sum = pNew->node.score[0] + pNew->node.score[1] + pNew->node.score[2];//�����ܳɼ�

				pNew->next = ptemp->next;
				ptemp->next = pNew;


				pNew = (List*)malloc(sizeof(List));
				printf("\n");
				printf("\t\t\t\t���������ѧ����ѧ��(������0)��");
				scanf("%s", pNew->node.num);
		}
		
	}
	free(pNew);
	return pHead;
}
//���ӵ�ָ��λ��
List *Readdate()
{
	FILE *fp;;

	List *pHead, *pEnd, *pNew = NULL;

	pHead = (List *)malloc(sizeof(List));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("stu_date.txt", "r")) == NULL)
	{
		fp = fopen("stu_date.txt", "w");
		getchar();

	}
	else
	{
		pNew = (List*)malloc(sizeof(List));
		while ((fread(pNew, sizeof(List), 1, fp))>0)
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
			pNew = (List*)malloc(sizeof(List));
		}

	}
	free(pNew);
	fclose(fp);
	return pHead;

}
//��ȡѧ�����ݵ�����
void Save_date_stu(List * pHead)
{
	FILE *fp = NULL;
	List * pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("ע����ϢΪ�գ��������������\n");
		getch();
		return 0;
	}
	fp = fopen("stu_date.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("�ļ���ʧ�ܣ��������������\n");
		getch();
	}
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(List), 1, fp);
		pTemp = pTemp->next;
	}
	fflush(fp);
	fclose(fp);
	printf("\t\t\t\t����ɹ�!�������������\n");
	getch();
	return;
}
//�������ݵ��ļ�
void  Query(List * pHead)
{
	List * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        ѧ����Ϣ��ѯ\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t������ѧ��ѧ�ţ�");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->node.num, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t�޸�ѧ������Ϣ\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\tѧ�ţ�%s\n", ptemp->node.num);
		printf("\t\t\t\t������%s\n", ptemp->node.name);
		printf("\t\t\t\t�Ա�%s\n", ptemp->node.sex);
		printf("\t\t\t\t�������ڣ�%d %d %d\n", ptemp->node.birthday.year, ptemp->node.birthday.month, ptemp->node.birthday.day);
		printf("\t\t\t\t��Ŀһ%.2f ��Ŀ��%.2f ��Ŀ��%.2f\n", ptemp->node.score[0], ptemp->node.score[1], ptemp->node.score[2]);
		printf("\t\t\t\t�ܳɼ���%.2f\n", ptemp->node.sum);
		printf("\t\t\t\t------------------------------------\n");
	}
}
//��ʦ�˲�ѯ��ѧ��
List* Delete_stu_bynum(List * pHead)
{
	List * ptemp = pHead, *ptemp1 = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        ѧ����Ϣɾ��\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t������ѧ��ѧ�ţ�");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->node.num, n) != 0)
	{
		ptemp1 = ptemp;
		ptemp = ptemp->next;
	}
	if (ptemp == NULL)
	{
		printf("\t\t\t\t�޸�ѧ������Ϣ��\n");
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
//ɾ��
List * Modify(List *pHead)
{
	List * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        ѧ����Ϣ�޸�\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t������ѧ��ѧ�ţ�");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->node.num, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t�޸�ѧ������Ϣ\n");
		getch();
		return NULL;
	}
	else
	{
		char c[20];
		int flag1 = 1;
		do
		{
			printf("\t\t\t\t1-����  2-�Ա�  3-��������   4-��Ŀһ  5-��Ŀ��  6-��Ŀ��  0-������һ��\n");
			printf("\t\t\t\t��������Ҫ�޸ĵ���Ϣ���:");
			scanf("%s", c);
			if (!strcmp(c, "1"))
			{
				printf("\t\t\t\t��������������");
				scanf("%s", ptemp->node.name);
			}
			else if (!strcmp(c, "2"))
			{
				printf("\t\t\t\t���������Ա�");
				scanf("%s", &ptemp->node.sex);
			}
			else if (!strcmp(c, "3"))
			{
				printf("\t\t\t\t�������³�������(�磺2018 5 12)��");
				scanf("%d %d %d", &ptemp->node.birthday.year, &ptemp->node.birthday.month, &ptemp->node.birthday.day);
			}
			else if (!strcmp(c, "4"))
			{
				float a;
				while (1)
				{
					printf("\t\t\t\t�������¿�Ŀһ�ɼ���");
					scanf("%f", &a);
					if (a > 0)
					{
						ptemp->node.score[0] = a;
						break;
					}
					else
					{
						printf("\t\t\t\t������Ϣ����\n");
						continue;

					}
				}
				
			}
			else if (!strcmp(c, "5"))
			{
				float a;
				while (1)
				{
					printf("\t\t\t\t�������¿�Ŀ���ɼ���");
					scanf("%f", &a);
					if (a > 0)
					{
						ptemp->node.score[1] = a;
						break;
					}
					else
					{
						printf("\t\t\t\t������Ϣ����\n");
						continue;

					}
				}
			}
			 else if (!strcmp(c, "6"))
			{
				float a;
				while (1)
				{
					printf("\t\t\t\t�������¿�Ŀ���ɼ���");
					scanf("%f", &a);
					if (a > 0)
					{
						ptemp->node.score[2] = a;
						break;
					}
					else
					{
						printf("\t\t\t\t������Ϣ����\n");
						continue;

					}
				}
			}
			else  if (!strcmp(c, "0"))
			{
				break;
			}
			else
			{
				printf("\t\t\t\t����������������룡");
			}
		} while (strcmp(c, "0"));
	}
	return pHead;
}
//�޸�
void  Query_nameandnum(List * pHead)
{
	List * ptemp = pHead;
	char name[20];
	char n[9];
	int flag = 1;
	while (flag) {
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        ѧ����Ϣ��ѯ\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t������ѧ��ѧ�ţ�");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\tѧ�ű���Ϊ8λ���֣�������\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else {
			flag = 0;
			printf("\t\t\t\t������ѧ��������");
			scanf("%s",name);
		}
	}
	
	while (ptemp&&strcmp(ptemp->node.num, n)&& strcmp(ptemp->node.name, name) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t�޸�ѧ������Ϣ\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\tѧ�ţ�%s\n", ptemp->node.num);
		printf("\t\t\t\t������%s\n", ptemp->node.name);
		printf("\t\t\t\t�Ա�%s\n", ptemp->node.sex);
		printf("\t\t\t\t�������ڣ�%d %d %d\n", ptemp->node.birthday.year, ptemp->node.birthday.month, ptemp->node.birthday.day);
		printf("\t\t\t\t��Ŀһ%.2f ��Ŀ��%.2f ��Ŀ��%.2f\n", ptemp->node.score[0], ptemp->node.score[1], ptemp->node.score[2]);
		printf("\t\t\t\t�ܳɼ���%.2f\n", ptemp->node.sum);
		printf("\t\t\t\t------------------------------------\n");
	}
}
//��ʦ�˲�ѯ��������ѧ��
List * Sort_by_sum(List* pHead)
{
	List *p, *q;
	int n=0, i, j;
	p = pHead;
	while (p)
	{
		n++;
		p = p->next;
	}
	for (i = 0; i<n - 2; i++)
	{
		p = pHead;
		q = p->next;
		for (j = 0; j<n - i - 2; j++)
		{
			if (q->node.sum<(q->next->node.sum))
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
	}


	return pHead;
}
//�ܳɼ���������
List * Sort_by_num(List* pHead)
{
	List *p, *q;
	int n = 0, i, j;
	p = pHead;
	while (p)
	{
		n++;
		p = p->next;
	}
	for (i = 0; i<n - 2; i++)
	{
		p = pHead;
		q = p->next;
		for (j = 0; j<n - i - 2; j++)
		{
			if (strcmp(q->node.num,q->next->node.num)>0)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
	}

	return pHead;
}
//ѧ����������
int judge_no(char num[], int len)
{
	int i;

	if (strlen(num) != len)
	{
		return 0;
	}
	for (i = 0; i<len; i++)
	{
		if (num[i] >= '0' && num[i] <= '9');
		else  break;
	}
	if (i == len) 
		return (1);
	else
	{
		return 0;
	}
}
//�ж�ѧ�������Ƿ���ȷ
void Analyzescore(List*pHead)
{
	List *p;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	p = pHead->next;
	if (p == NULL)
	{
		printf("\t\t\t\t��������!�����������\n");
		getch();
		return 0;
	}
	while (p)
	{
		if (p->node.score[0] < 60)
			sum1++;
		if (p->node.score[1] < 60)
			sum2++;
		if (p->node.score[2] < 60)
			sum3++;
		p = p->next;
	}
	printf("\t\t\t\t----------------------------------------------\n");
	printf("\t\t\t\t                 �ɼ�����\n");
	printf("\t\t\t\t----------------------------------------------\n");
	printf("\t\t\t\t             ��Ŀһ������������%d��\n", sum1);
	printf("\t\t\t\t             ��Ŀ��������������%d��\n", sum2);
	printf("\t\t\t\t             ��Ŀ��������������%d��\n", sum3);
	printf("\t\t\t\t----------------------------------------------\n");
	printf("\t\t\t\t�������������");
	getch();
}
//�ɼ�����
void Printf_list(List *pHead)
{
	int num = 1;
	List * p = pHead->next;
	if (p == NULL)
	{
		printf("\t\t\t\t��������!�����������\n");
		getch();
		return 0;
	}
	while (p != NULL)
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t�ܳɼ�������%d\n", num);
		printf("\t\t\t\tѧ�ţ�%s\n", p->node.num);
		printf("\t\t\t\t������%s\n", p->node.name);
		printf("\t\t\t\t�Ա�%s\n", p->node.sex);
		printf("\t\t\t\t�������ڣ�%d %d %d\n", p->node.birthday.year, p->node.birthday.month, p->node.birthday.day);
		printf("\t\t\t\t��Ŀһ%.2f ��Ŀ��%.2f ��Ŀ��%.2f\n", p->node.score[0], p->node.score[1], p->node.score[2]);
		printf("\t\t\t\t�ܳɼ���%.2f\n", p->node.sum);
		printf("\t\t\t\t------------------------------------\n");
		p = p->next;
		num++;
	}
}
//��ӡ����������Ϣ
void Printf_numlist(List *pHead)
{
	List * p = pHead->next;
	if (p == NULL)
	{
		printf("\t\t\t\t��������!�����������\n");
		getch();
		return 0;
	}
	while (p != NULL)
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\tѧ�ţ�%s\n", p->node.num);
		printf("\t\t\t\t������%s\n", p->node.name);
		printf("\t\t\t\t�Ա�%s\n", p->node.sex);
		printf("\t\t\t\t�������ڣ�%d %d %d\n", p->node.birthday.year, p->node.birthday.month, p->node.birthday.day);
		printf("\t\t\t\t��Ŀһ%.2f ��Ŀ��%.2f ��Ŀ��%.2f\n", p->node.score[0], p->node.score[1], p->node.score[2]);
		printf("\t\t\t\t�ܳɼ���%.2f\n", p->node.sum);
		printf("\t\t\t\t------------------------------------\n");
		p = p->next;
	}
}
//��ӡѧ��������Ϣ
void Query_stu(List *pHead,char *p)
{
	List * ptemp = pHead;
	int flag = 1;
	while (ptemp&&strcmp(ptemp->node.num, p) != 0)
		 ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t��Ϣ��δ¼��\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		printf(" \n");
		printf(" \n");
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\tѧ�ţ�%s\n", ptemp->node.num);
		printf("\t\t\t\t������%s\n", ptemp->node.name);
		printf("\t\t\t\t�Ա�%s\n", ptemp->node.sex);
		printf("\t\t\t\t�������ڣ�%d %d %d\n", ptemp->node.birthday.year, ptemp->node.birthday.month, ptemp->node.birthday.day);
		printf("\t\t\t\t��Ŀһ%.2f ��Ŀ��%.2f ��Ŀ��%.2f\n", ptemp->node.score[0], ptemp->node.score[1], ptemp->node.score[2]);
		printf("\t\t\t\t�ܳɼ���%.2f\n", ptemp->node.sum);
		printf("\t\t\t\t------------------------------------\n");
	}
}
//��¼�û��ĸ�����Ϣ
void Analy_stu(List *pHead, char *p)
{
	List * ptemp = pHead;
	int flag = 1;
	while (ptemp&&strcmp(ptemp->node.num, p) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t��Ϣ��δ¼��\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		int flag = 0;
		printf(" \n");
		printf(" \n");
		printf("\t\t\t\t------------------------------------\n");
		if (ptemp->node.score[0] < 60)
		{
			flag = 1;
			printf("\t\t\t\t��Ŀһ���ϸ�\n");
		}
		if (ptemp->node.score[1] < 60)
		{
			flag = 1;
			printf("\t\t\t\t��Ŀ�����ϸ�\n");
		}
			
		if (ptemp->node.score[2] < 60)
		{
			flag = 1;
			printf("\t\t\t\t��Ŀ�����ϸ�\n");
		}
		if (flag == 1)
			printf("\t\t\t\tǱ��ѧϰ�������Ծ����ͣ�\n");
		else if (flag == 0)
			printf("\t\t\t\tȫ���ϸ񣬲������ģ�������ǰ��\n");
		printf("\t\t\t\t------------------------------------\n");
	}
}
//������¼�û������ɼ�
void Exit()
{
	int i;
	goto_xy(50,8);
	for (i = 0; i < 5; i++)
	{
		printf("�� ");
		Sleep(200);
	}
}
//�˳�
List * outsidefile(char *p)
{
	FILE *fp;
	List *pNew, *pHead;
	pHead = (List *)malloc(sizeof(List));
	pHead->next = NULL;
	pNew = (List *)malloc(sizeof(List));
	
	if (fp = fopen(p, "r") ,fp== NULL)
	{
		printf("\t\t\t\t�ļ������ڣ�");
		return NULL;
	}

	while (!feof(fp))
	{

		fscanf(fp, "%s %s %s %d %d %d %f %f %f %lf", pNew->node.num, pNew->node.name, pNew->node.sex, &pNew->node.birthday.year, &pNew->node.birthday.month, &pNew->node.birthday.day, &pNew->node.score[0], &pNew->node.score[1], &pNew->node.score[2], &pNew->node.sum);
		pNew->next = NULL;
		pNew->next = pHead->next;
		pHead->next = pNew;

		pNew = (List *)malloc(sizeof(List));
	}
	free(pNew);
	fclose(fp);
	return pHead;
}
//�ⲿ����ѧ����Ϣ
void stu_select(char * p)
{
	List * pHead;
	char a[100];
	do {
		system("cls");
		second_stu();
		goto_xy(50, 15);
		printf("����������ѡ��");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead=Readdate();
			Query_stu(pHead,p);
			printf("\t\t\t\t�����������\n");
			getch();
		}
		else if (strcmp("2", a) == 0)
		{
			pHead = Readdate();
			Analy_stu(pHead, p);
			printf("\t\t\t\t�����������\n");
			getch();
		}

		else if (strcmp("3", a) == 0)
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
//ѧ��
void tea_select()
{
	List * pHead = NULL;
	char a[100];
	do {
		system("cls");
		second_tea();
		goto_xy(50, 14);
		printf("����������ѡ��");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead = Readdate();
			pHead = Input_stu(pHead);
			Save_date_stu(pHead);	
		}
		else if (strcmp("2", a) == 0)
		{

			pHead = Readdate();
			pHead = Increase_stu(pHead);
			Save_date_stu(pHead);
		}
		else if (strcmp("3", a) == 0)
		{
			pHead = Readdate();
			pHead = Delete_stu_bynum(pHead);
			Save_date_stu(pHead);
		}
		else if (strcmp("4", a) == 0)
		{
			pHead = Readdate();
			pHead = Modify(pHead);
			Save_date_stu(pHead);
			
		}
		else if (strcmp("5", a) == 0)
		{
			int n;
			printf("\t\t\t\t��ѡ���ѯ��ʽ  1.��ѧ�Ų�ѯ  2.ѧ�ż����ֲ�ѯ��");
			scanf("%d", &n);
			pHead = Readdate();
			if (n == 1) {
				Query(pHead);
			}
			else if(n==2){
				Query_nameandnum(pHead);
			}
			printf("\t\t\t\t�������������\n");
			getch();
		}
		else if (strcmp("6", a) == 0)
		{
			pHead = Readdate();
			int n;
			printf("\t\t\t\t��ѡ���ѯ��ʽ  1.���ɼ��������  2.��ѧ�����������");
			scanf("%d", &n);
			if (n == 1) {
				pHead = Sort_by_sum(pHead);
				Printf_list(pHead);
			}
			else if (n == 2) {
				pHead=Sort_by_num(pHead);
				Printf_numlist(pHead);
			}
			printf("\t\t\t\t�������������\n");
			getch();
		}
		else if (strcmp("7", a) == 0)
		{
			pHead = Readdate();
			Analyzescore(pHead);
		}
		else if (strcmp("8", a) == 0)
		{
			char filename[50];
			printf("\t\t\t\t�����뵼���ļ��ļ��ľ���·����");
			scanf("%s", filename);
			if (pHead=outsidefile(filename),pHead == NULL)
			{
				printf("\t\t\t\t��·�����ļ������ڣ��������������");
				getch();
			}
			else
			{
				Save_date_stu(pHead);
			}
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
//��ʦ