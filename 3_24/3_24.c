#define _CRE_SECURE_NO_WARNINGS
#include<stdio.h>

//#define square(x) x*x
//int main()
//{
//	int r = square(5);
//	//�궨������д����ֱ���滻���д��5+1�ͻ���ʾ11
//
//	int r = square(5 + 1);
//	//int r = 5 + 1 * 5 + 1;
//	//
//	
//	printf("%d\n", r);
//	return 0;
//}

//#define SQUARE(x) ((x)*(x))
//int main()
//{
//	int r = SQUARE(5 + 1);
//	printf("%d\n", r);
//	return 0;
//}
//


//int main()
//{
//	printf("hello world\n");
//	printf("hello ""world");//���ߵȼۣ����߻��Զ�������һ���ַ�������
//}

//#define PRINT(N) printf("The value of "#N" is %d\n",N)
//
//int main()
//{
//	int a = 10;
//	PRINT(a);
//	
//	int b = 20;
//	PRINT(b);
//	return 0;
//}

//#define PRINT(N,FORMAT) printf("the value of "#N" is "FORMAT"\n",N)
//
//
//int main()
//{
//	int a = 10;
//	PRINT(a, "%d");
//	
//	float f = 3.14f;
//	PRINT(f, "%lf");
//
//	return 0;
//}

#define  MAX(a,b)  ((a)>(b)?(a):(b))

//int main()
//{
//	int a = 5;
//	int b = 4;
//	int m = MAX(a++, b++);
//	//int m = ((a++) > (b++) ? (a++) : (b++));
//	   //6     5   >    4	?  6		
//	printf("m = %d ", m);//6
//	printf("a = %d b = %d\n", a, b);//7 5
//	return 0;
//}



////����һ
//#ifndef __TEST_H__
//#define __TEST_H__
//
//int Add(int x, int y);
//
//#endif
//
//
////������
//#pragma once
//
//int Add(int x, int y);
////���ö��ǣ���ֹͷ�ļ�������ظ��İ���