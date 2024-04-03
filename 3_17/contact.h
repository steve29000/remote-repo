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


//���͵�����

//�˵���Ϣ
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;


//ͨѶ¼

//��̬�汾
//typedef struct contact
//{
//	peoinfo data[MAX];//����˵���Ϣ
//	int count;//��¼��ǰͨѶ¼��ʵ���˵ĸ���
//}contact;

//��̬�汾
typedef struct contact
{
	peoinfo *data;//����˵���Ϣ
	int count;//��¼��ǰͨѶ¼��ʵ���˵ĸ���
	int capacity;//��ǰͨѶ¼������

}contact;


//��ʼ��ͨѶ¼
int Initcontact(contact* pc);

//��������
void Destroycontact(contact* pc);

//����ָ����ϵ��
int Addcontact(contact* pc);

//��ӡͨѶ¼����
void Showcontact(contact* pc);

//ɾ��ָ����ϵ��
void Delcontact(contact* pc);

//����ָ����ϵ��
void Searchcontact(contact* pc);

//�޸�ָ����ϵ��
void Modifycontact(contact* pc);

//������������
void Sortcontact(contact* pc);

//����ͨѶ¼��Ϣ���ļ�
void Savecontact(const contact* pc);

//�����ļ���Ϣ��ͨѶ¼
void Savecontact(contact* pc);
