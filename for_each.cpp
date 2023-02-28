#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string>
void myPrint(int a)
{
    std::cout << a << " ";
}

class person
{
public:
    int age;
    std::string name;
    person(int a, const std::string &n) : age(a), name(n) {}
};
class person_p  //  仿函数
{

public:
    void operator()(person &per) const
    {
        std::cout << "name:" << per.name << " age: " << per.age << std::endl;
    }
};
int main()
{

    std::vector<int> v;
    for (int a = 0; a < 10; a++)
    {
        v.push_back(a);
    }

    for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }

    std::cout << "for_each on fall" << std::endl;

    std::for_each(v.begin(), v.end(), myPrint);
    std::cout << std::endl;

    person per(22, "hello");
    std::vector<person> vp;
    vp.push_back(per);
    vp.push_back(person(23, "wrold !"));
    person_p func; // 仿函数实例化
    
    std::for_each(vp.begin(), vp.end(), func);
    std::for_each(vp.begin(), vp.end(), person_p()); // 匿名对象的方式
}