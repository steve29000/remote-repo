#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contact.h"
//
//1.��̬�汾
//2.��̬�汾
//3.�ļ��汾
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
	
	contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	Initcontact(&con);

	do
	{
		menu();
		printf("��ѡ��:>");
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
				printf("�˳�ͨѶ¼\n");
				break;
			default:
				printf("ѡ�����\n");
				break;
					

		}

	} while (input);

	return 0;
}