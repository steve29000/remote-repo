#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contact.h"


//��̬�汾
//void Initcontact(contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}



void checkcapacity(contact* pc)
{
	if (pc->count == pc->capacity)
	{
		peoinfo* ptr = (peoinfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(peoinfo));
		if (ptr == NULL)
		{
			printf("ADDcontact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
	}
}


void Loadcontact(contact* pc)
{
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)
	{
		perror("Loadcontact");
		return;
	}

	peoinfo tmp = { 0 };

	while (fread(&tmp, sizeof(peoinfo), 1, pfread))
	{
		checkcapacity(pc);

		pc->data[pc->count] = tmp;
		pc->count++;
	}


	fclose(pfread);
	pfread = NULL;
}


//��̬�汾
int Initcontact(contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (peoinfo*)calloc(DEFAULT_SZ , sizeof(peoinfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	//�����ļ���Ϣ��ͨѶ¼��
	Loadcontact(pc);

	return 0;
}

void Destroycontact(contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc = NULL;//Ҳ����pc���ó�NULL 
}


//��̬�汾
//void Addcontact(contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	printf("����������:>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("����������:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("�������Ա�:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("������绰:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("�������ַ:>");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("���ӳɹ�\n"); 
//}



//��̬�汾
int Addcontact(contact* pc)
{
	assert(pc);
	checkcapacity(pc);
	printf("����������:>");
	scanf("%s", pc->data[pc->count].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ�\n");
}



//��ӡͨѶ¼�е���Ϣ
void Showcontact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
													pc->data[i].age,
												    pc->data[i].sex, 
													pc->data[i].tele,
													pc->data[i].addr);
	}
}

static int Findbyname(contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


void Delcontact(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����Ϣ����ɾ��");
		return;
	}
	printf("������Ҫɾ���˵�����:>");
	scanf("%s",name);

	//ɾ��
	//1. ����
	int pos = Findbyname(pc,name);
	if (pos == 1)
	{
		printf("Ҫɾ�����˲�����");
		return;
	}
	//2. ɾ��
	for (i = pos; i < pc->count; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;

	printf("ɾ���ɹ�\n");
}


void Searchcontact(contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//1.����
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	//2.��ӡ
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);

}


void Modifycontact(contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	//1.����
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("Ҫ�޸��˵���Ϣ�Ѿ����ҵ��������������޸�\n");
	//2.�޸�
	printf("����������:>");
	scanf("%s", pc->data[pos].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pos].addr);

	printf("�޸ĳɹ�\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
}

void Sortcontact(contact* pc)
{
	assert(pc);
	qsort(pc->data,pc->count,sizeof(peoinfo), cmp_peo_by_name);
	printf("����ɹ�");

}


void Savecontact(const contact* pc)
{
	assert(pc);
	FILE* pfwrite = fopen("contact.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("Savecontact");
		return;
	}

	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data+i, sizeof(peoinfo), 1, pfwrite);
	}


	fclose(pfwrite);
	pfwrite = NULL;

}