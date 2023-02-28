/*************************************************************************
	> File Name: vector.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/13 15:59:46 2022
 ************************************************************************/

#include <iostream>
#include <vector>
// vector 是C++98 引入的动态数组（dynamic array)
// 特点：随机访问元素，末端添加删除元素效率高 前和中删除和添加效率低，
//		存在当前容器大小和容量的关系
//  配置新空间-数据移动-释放旧空间
using namespace std;
int main()
{

	using Group = vector<int>; //	起别名
	typedef vector<int> Group;

	Group a;
	Group b(a);
	Group c = b;
	vector<int> vec;					  // vector<Data_Types> name;
	vector<int> v1;						  //创建一个空的向量v1
	vector<int> v2(10);					  //创建一个向量v2，其已开辟10个元素的空间，相当于int v[10];
	vector<int> v3(10, 5);				  //创建一个向量v3，其已开辟10个元素的空间并全部赋值为5
	vector<int> v4(v3.begin(), v3.end()); //创建一个向量v3,其内容为向量v3的内容
	vector<int> v5(v4);					  //创建一个向量v5，其包含了v4的全部内容

	a.empty();
	a.size();
	a.max_size();
	a.capacity();	   //返回容量大小
	a.reserve(100);	   // 预先分配100的容量
	a.shrink_to_fit(); // c++11

	//赋值
	vector<float> d;
	d.assign(3, 1.0f);
	d.assign(a.begin(), a.end()); // d = a
	d.assign({1.0f, 2.0f, 3.0f});

	//交换
	a.swap(b);
	std::swap(a, b);

	// 元素访问
	a[0];
	a.at(0);   // 会有检查 异常抛出
	a.front(); //使用前一点要检查 容器是否为空 a.empty(); 不然程序会崩溃
	a.back();  // a.empty();

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back(); // single thread  多线程下可能错误
	if (!a.empty())
		a.pop_back();

	a.erase(a.begin());			//删除特定位置的元素
	a.erase(a.begin(), a.end());// 删除区间的元素

		a.push_back(1.0f);
	auto iter = a.insert(a.end(), 1.0f);		  //插入元素 返回插入位置的迭代器
	iter = a.insert(a.end(), 10, 1.0f);			  //在插入处开始插入10个1.0f的元素
	iter = a.insert(a.end(), b.begin(), b.end()); //插入其他容器的区间
	a.emplace(a.end(), 1.0f);					  // c++11
	a.emplace_back(10.0f);
	a.resize(10);	  //重新设置size大小
	a.clear();		  //清空元素  但是容量不变
	a.shrink_to_fit(); // c++11 降低内存

	//特殊
	// 一定不要用 std::vector<bool> vecb;

	for (int i = 0; i < 10; i++) //测试装入10个整数
	{
		vec.push_back(i);
	}
	auto it = vec.begin();
	cout << typeid(it).name() << endl;
	cout << "test vec! out" << endl;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl; //输出测试迭代器iterator
	}
	for (int i = 0; i < 5; i++)
	{
		vec.pop_back(); //删除五个尾部的数据 注意⚠️ （）内没有元素
	}
	cout << "pop_back() 五次后的vec" << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "最大可装 可申请的内存：vec.max_size() = ";
	cout << vec.max_size();
	cout << "个int" << endl;
	cout << "已经开辟的空间大小：( vec.capacity() ) :" << vec.capacity() << endl;
	cout << "vec.size() 现在vec中的元素个数：" << vec.size() << endl;

	cout << "vec.insert(vec.begin(),10): ";
	vec.insert(vec.begin(), 10); // 可以insert（vec.begin() ,v3.begin(),v3.end()）
								 // 将v3插入到begin（）位置
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "删除前四个元素：vec.erase(vec.begin(),vec.begin() + 4) :";
	vec.erase(vec.begin(), vec.begin() + 4);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "删除所有元素： vec.clear() :";
	vec.clear();
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "删除后size（）:" << vec.size() << endl;
	cout << "删除后capacity() :" << vec.capacity() << endl;
}
