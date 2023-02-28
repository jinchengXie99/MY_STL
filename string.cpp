/*************************************************************************
	> File Name: string.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  3/14 16:02:34 2022
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{

	string s("abcdef"); // string(const char*)

	cout << s << endl; // abcdef

	string s1(10, 'h'); // string(int n, char ' ') //n个字符
	cout << s1 << endl; // hhhhhhhhhh

	string s2(s1);		// copy构造
	cout << s2 << endl; // hhhhhhhhhh

	string s3;
	s3.assign("hello"); // 字符串赋值
	cout << s3 << endl; // hello

	string s4;
	s4.assign("hello world", 5); // 字符串前5个赋值
	cout << s4 << endl;			 // hello

	string s7;
	s7.assign("helllbablooooo", 3, 6); // 从下标3开始位置取6个字符
	cout << s7 << endl;				   // llbabl

	string s5;
	s5.assign(s4);		// s4赋值给s5
	cout << s4 << endl; // hello

	string s6;
	s6.assign(10, 'A'); // n=10个字符赋值给s6
	cout << s6 << endl; // AAAAAAAAAA

	string str8("hello world");
	std::cout << str8[1] << std::endl;	  // e
	std::cout << str8.at(1) << std::endl; // e
	str8[1] = 'E';						  // hEllo world
	str8.at(6) = 'W';					  // hEllo World
	std::cout << str8 << std::endl;		  // hEllo World

	// [] 和 at 的区别：
	try
	{
		// str8[100] = 'G'; // 越界不会抛出任何异常
		str8.at(100) = 'G'; // 会抛出异常
	}
	catch (exception &e)
	{
		std::cout << "异常：" << e.what() << std::endl;
	}

	// string 的拼接
	std::string str9("hello");
	std::string str10(" world");
	str9 += str10;
	cout << str9 << endl; // hello world

	string s11("xie jin cheng ");
	s11 += "LOVE xie wen jing";
	std::cout << s11 << std::endl; // xie jin cheng LOVE xie wen jing

	string str12("hello");
	str12.append("xie jin cheng", 3); // 添加前3个字符
	std::cout << str12 << std::endl;  // helloxie

	string str13("hello ");
	str13.append("xie jin cheng ", 3, 9); // 添加区间 从下标3开始取9个字符
	std::cout << str13 << std::endl;	  // hello  jin chen

	// 字符串查找
	std::string str14("hello world xie jin cheng ");
	std::string str15("xie");

	int pos = str14.find(str15, 0); // 默认从0开始找
	if (pos != -1)
	{ // 没找到返回-1
		cout << "find pos: " << pos << endl;
	}
	str14.replace(5, 4, "######");	 // 从下标5开始替换4个字符位置 为 ######
	std::cout << str14 << std::endl; // hello######ld xie jin cheng

	// 需求：将敏感词替换为***
	std::string str16("www.sex.123890.sex.com");
	int ret = 0;
	while ((ret = str16.find("sex")) != -1)
	{
		str16.replace(ret, strlen("sex"), "***");
	}
	std::cout << str16 << std::endl;

	//字符串比较
	std::string str17("hehahe");
	std::string str18("xiejincheng");
	std::cout << str17.compare(str18) << std::endl;	   // -16
	std::cout << str17.compare("oo") << std::endl;	   // -7
	std::cout << str18.compare(str17) << std::endl;	   // 16
	std::cout << str17.compare("hehahe") << std::endl; // 0

	// 子字符串提取  // 以 ":" 分割子串
	std::string str19("heha:hah:hhhh:xxx:wahat:xie:jin:cheng");
	ret = 0;
	pos = 0;
	while (1)
	{
		ret = str19.find(":", pos);
		if (ret < 0)
		{
			// 最后一个':'
			std::cout << str19.substr(pos, str19.size() - pos) << std::endl;
			break;
		}
		std::cout << str19.substr(pos, ret - pos) << std::endl;
		pos = ret + 1;
	}

	// 字符串的插入 删除 清空
	std::string str20("hello jin cheng");
	str20.insert(6, "xie ");
	std::cout << str20 << std::endl; // hello xie jin cheng

	str20.erase(6, 4);				 // 从下标6开始删除4个字符
	std::cout << str20 << std::endl; // hello jin cheng

	str20.clear(); // 	清空字符串
	std::cout << str20 << std::endl;
	std::cout << str20.size() << std::endl; // 0

	// C风格str 到 C++的string
	std::string str21;
	const char *cstr = "hello xie jin cheng";

	str21 = cstr;
	std::cout << str21 << std::endl; // hello xie jin cheng

	char *cstr1 = const_cast<char *>(str21.c_str()); // 去掉const属性
	std::cout << cstr1 << std::endl;				 // hello xie jin cheng

	char const *cstr2 = str21.c_str(); // 默认c_str 返回的是 const char *
	std::cout << cstr2 << std::endl;   // hello xie jin cheng

	return 0;
}
