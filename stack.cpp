/*************************************************************************
	> File Name: stack.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/13 18:42:40 2022
 ************************************************************************/

#include <iostream>
#include <stack>
#include <deque>
#include <queue>
using namespace std;
int main()
{
	stack<int> t;

	t.push(10);
	if (!t.empty())
	{
		cout << t.top() << endl;
	}
	t.pop();
	// cout << t.top() << endl;  // t.top() 返回栈顶元素 用前记得判空操作
	if (t.empty())
	{
		cout << "空" << endl;
	}
	cout << t.size() << endl; // t.size() 返回堆栈的大小

	return 0;
}
