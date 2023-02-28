/*************************************************************************
	> File Name: array.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  4/ 5 18:22:25 2022
 ************************************************************************/

#include <iostream>
#include <array> // 在栈上分配内存 绝对不重新分配内存 随机访问内存
int main()
{
	std::array<int, 100> a;
	std::array<int, 100> b = {};
	for (auto i : b)
	{
		std::cout << i << std::endl;
	}
	//接口
	b.empty(); // never be true if size > 0  一直有元素
	b.size();
	b.max_size();

	// operator == < != > <= >=
	a.swap(b);
	swap(a, b);

	// 访问元素
	a[0];
	a.at(0);
	a.front(); //返回最前面的元素引用
	a.back();  // 返回最后一个元素

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin(); // c 代表const &   只读
	a.cend();
	a.rbegin(); // r 从尾到头  顺序颠倒
	a.rend();
	a.crbegin();
	a.crend();

	// 和C的接口互用
	std::array<char, 100> carr;
	strcpy(&carr[0], "Hello world!\n");
	printf("%s", &carr[0]); // more better use carr.data()

	//错误用法
	// printf ("%s",carr.begin());

	//特殊用法
	auto info = std::get<1>(carr); //得到序号为1 的位置
	carr.fill(0);				   //所有元素赋值为0

	//异常 exception
	// a.at(pos)
	// copy move swap
}
