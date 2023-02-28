#include <iostream>
#include <string>
using namespace std; //标准命名空间
namespace hello
{
	string name = "xiao ming";
	namespace world
	{

		int age = 10;
	}
}

namespace hello
{
	string name2 = "xie Jin cheng";
}
namespace
{

	string name = "匿名空间 相当于static";
}
int main()
{
	// cout是标准的输出流对象，打印字符串，
	// endl是刷新缓冲区，并换行
	namespace nihao = hello;
	cout << hello::name << endl;
	cout << hello::world::age << endl;
	cout << hello::name2 << endl;
	cout << name << endl;
	cout << nihao::name << endl;
}