/*************************************************************************
	> File Name: queue.cpp
	> Author: Jincheng Xie
	> Mail: chengdiy@foxmail.com
	> Created Time: 日  5/15 19:52:58 2022
 ************************************************************************/

#include <iostream>
#include <queue> // 单向队列 先进先出
using namespace std;
int main()
{
	queue<int> q;
	for (int i = 100; i > 0; i--)
	{
		q.push(i); // 入队
	}
	cout << q.back() << endl;  // 返回最后一个元素
	cout << q.front() << endl; // 返回最前面的元素

	if (!q.empty()) // 判空
	{
		q.pop(); // 最前面的第一个元素出队列（移除）
	}

	cout << q.front() << endl; // 返回最前面的元素

	cout << q.size() << endl; // 返回队列元素个数（大小）
}
