/*************************************************************************
	> File Name: malloc.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/13 01:13:15 2022
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int *p;
	p = (int *)malloc(sizeof(int) * 10); // 在堆申请内存 10个int类型的大小
	if (p == NULL)
	{
		exit(1);
	} //如果申请失败 退出
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	cout << p[5] << endl;
	free(p);  //
	p = NULL; //
	return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
int main(){
  int *p;     //定义一个指向整形的指针变量
	p=(int*)malloc(5*sizeof(int));  //申请5个整形大小的内存空间并返回起始地址给p
	if(p==NULL){    //申请失败
	//执行申请失败的代码，一般print一个报错
		exit(1);    //退出
	}
	p[0]=1000;  //为空间中添加数据
	printf("%d",p[0]);  //打印这个数据
	free(p);    //释放p的内存空间，此时p依旧存在，只不过失去了指向的对象，成了野指针
	p=NULL; //为其赋NULL，此时它不再是一个野指针
	return 0;
}  */
