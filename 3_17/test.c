#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contact.h"
//
//1.静态版本
//2.动态版本
//3.文件版本
//


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


void menu()
{
	printf("************************************\n");
	printf("******  1.add      2.del    ********\n");
	printf("******  3.search   4.modify ********\n");
	printf("******  5.show      6.sort  ********\n");
	printf("******  0.exit		        ********\n");
	printf("************************************\n");
	
}

int main()
{
	int input = 0;
	
	contact con;//通讯录
	//初始化通讯录
	Initcontact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				Addcontact(&con);
				break;
			case DEL:
				Delcontact(&con);
				break;
			case SEARCH:
				Searchcontact(&con);
				break;
			case MODIFY:
				Modifycontact(&con);
				break;
			case SHOW:
				Showcontact(&con);
				break;
			case SORT:
				Sortcontact(&con); 
				break;

			case EXIT :
				Savecontact(&con);
				Destroycontact(&con);
				printf("退出通讯录\n");
				break;
			default:
				printf("选择错误\n");
				break;
					

		}

	} while (input);

	return 0;
}