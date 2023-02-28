#include <iostream>
#include <stdexcept>
using namespace std;
template <class T>
T dev(T a, T b)
{
    if (b == 0)
    {
        throw "c";
        cout << "Dev end..." << endl;
    }

    return a / b;
}
class Maker
{
public:
    Maker(int a)
    {
        this->a = a;
        cout << "普通构造函数" << endl;
    }
    Maker(const Maker &b)
    {
        this->a = b.a;
        cout << "拷贝构造函数" << endl;
    }
    ~Maker()
    {
        cout << "析构函数。。。" << endl;
    }

    int a;
};
void func()
{
    
    throw out_of_range("擦后范围");
    cout << "throw 后续···" << endl;
}
int main()
{
    try
    {
        func();
        cout << "func 后续"  << endl;
    }
    catch (int b)
    {
        cout << "throw b " << b << endl;
    }
    catch (Maker* m)
    {
        cout << "throw one Maker Exception" << endl;
        delete m;
    }
    catch(out_of_range& ex){
        cout << ex.what() << endl;
    }
    catch(...){
        cout << "throw one Exception" << endl;
    }
}