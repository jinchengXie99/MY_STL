/*************************************************************************
	> File Name: list.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/13 17:27:21 2022
 ************************************************************************/

#include <iostream>
#include <list>
using namespace std;
void print(list<int> &l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	list<int> l1;						// 创建一个链表
	list<int> l2(10);					//创建一个列表其中有10个空元素
	list<int> l3(5, 10);				//创建一个含五个元素内容为10的列表
	list<int> l4(l3.begin(), l3.end()); //创建内容为l3的列表
	list<int> l5(l4);					//	创建一个内容为l4的列表

	print(l1);
	//	l1.empty()	判空   空为ture  不空为false
	cout << l1.empty() << endl; // 输出1
	l1.push_front(10);			// 在列表的前面插入10

	print(l1);
	l1.pop_front(); //删除第一个元素

	l1.push_back(10); //尾插
	l1.pop_back();	  //尾删

	//  insert()
	//  erase()
	//  都和vector 一样
	for (int i = 1; i < 11; i++)
	{
		l1.push_front(i);
	}
	cout << "sort:";
	l1.sort(); //从小到大排序
	print(l1);

	cout << "reverse:";
	l1.reverse(); //从大到小排序
	print(l1);
	return 0;
}

