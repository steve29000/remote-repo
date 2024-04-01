#define _CRE_SECURE_NO_WARNINGS
#include<stdio.h>

//#define square(x) x*x
//int main()
//{
//	int r = square(5);
//	//宏定义这种写法是直接替换如果写成5+1就会显示11
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
//	printf("hello ""world");//两者等价，后者会自动接在上一个字符串后面
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



////方案一
//#ifndef __TEST_H__
//#define __TEST_H__
//
//int Add(int x, int y);
//
//#endif
//
//
////方案二
//#pragma once
//
//int Add(int x, int y);
////作用都是：防止头文件被多次重复的包含