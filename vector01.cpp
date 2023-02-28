#include <vector>
#include <iostream>
#include <algorithm>

void test01()
{
    std::vector<int> v;
    for(int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    std::cout << "容量：" << v.capacity() << std::endl;
    std::cout << "长度：" << v.size() << std::endl;
}
void test02()
{
    std::vector<int> v;
    int * p = nullptr;
    int count = 0;
    for (int i = 0; i < 1000; ++i)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            ++count;
            p = &v[0];
        }
    }
    std::cout << "另寻空间次数：" << count << std::endl;
}
int main ()
{

    test02();
}
