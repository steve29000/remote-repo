#pragma once
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define DEFAULT_SZ 3
#define INC_SZ 2
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30


//类型的声明

//人的信息
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;


//通讯录

//静态版本
//typedef struct contact
//{
//	peoinfo data[MAX];//存放人的信息
//	int count;//记录当前通讯录的实际人的个数
//}contact;

//动态版本
typedef struct contact
{
	peoinfo *data;//存放人的信息
	int count;//记录当前通讯录的实际人的个数
	int capacity;//当前通讯录的容量

}contact;


//初始化通讯录
int Initcontact(contact* pc);

//销毁数据
void Destroycontact(contact* pc);

//增加指定联系人
int Addcontact(contact* pc);

//打印通讯录的人
void Showcontact(contact* pc);

//删除指定联系人
void Delcontact(contact* pc);

//查找指定联系人
void Searchcontact(contact* pc);

//修改指定联系人
void Modifycontact(contact* pc);

//按照名字排序
void Sortcontact(contact* pc);

//保存通讯录信息到文件
void Savecontact(const contact* pc);

//加载文件信息到通讯录
void Savecontact(contact* pc);
