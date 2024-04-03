#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contact.h"


//静态版本
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
			printf("增容成功\n");
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


//动态版本
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
	//加载文件信息到通讯录中
	Loadcontact(pc);

	return 0;
}

void Destroycontact(contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc = NULL;//也可以pc设置成NULL 
}


//静态版本
//void Addcontact(contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("增加成功\n"); 
//}



//动态版本
int Addcontact(contact* pc)
{
	assert(pc);
	checkcapacity(pc);
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}



//打印通讯录中的信息
void Showcontact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
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
		printf("通讯录为空，没有信息可以删除");
		return;
	}
	printf("请输入要删除人的名字:>");
	scanf("%s",name);

	//删除
	//1. 查找
	int pos = Findbyname(pc,name);
	if (pos == 1)
	{
		printf("要删除的人不存在");
		return;
	}
	//2. 删除
	for (i = pos; i < pc->count; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;

	printf("删除成功\n");
}


void Searchcontact(contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1.查找
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//2.打印
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
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
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	//1.查找
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("要修改人的信息已经查找到，接下来进行修改\n");
	//2.修改
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
}

void Sortcontact(contact* pc)
{
	assert(pc);
	qsort(pc->data,pc->count,sizeof(peoinfo), cmp_peo_by_name);
	printf("排序成功");

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

	//写文件
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data+i, sizeof(peoinfo), 1, pfwrite);
	}


	fclose(pfwrite);
	pfwrite = NULL;

}