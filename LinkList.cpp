/*************************************************************************
	> File Name: LinkList.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/13 09:55:41 2022
 ************************************************************************/

#include <iostream>
using namespace std;
typedef struct LinkNode
{
	int date;
	LinkNode *next = NULL;
} Node;
Node *LinkedListcreatH()
{
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	if (L == NULL)
	{
		printf("申请堆内存失败!\n");
		exit(1);
	}

	L->next = NULL;
	L->date = 100;
	cout << L->date << endl;
	return L;
}
int main()
{
	Node *L;
	L = LinkedListcreatH();
	free(L);
	return 0;
}
