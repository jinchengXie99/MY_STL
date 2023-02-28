#include <iostream>
#include <string>
using namespace std;

template <class T>
void  mySwap(T& a,T& b)
{
    T t = a;
    a = b; 
    b = t;
}
template<class T>
T add(T& a, T& b){
    return a+b;
}

double add(double &a, double &b)
{
    return a+b;
}


template<class T1,class T2=int>
class Maker{
    public:
    Maker (const T1& a, const T2& b){
        this->a = a;
        this->b = b;
    }
    void print(){
        cout << a << " " << b <<endl;
    }
    private:
    T1 a;
    T2 b;
};

int main (){

    Maker<string> a("你好",10);
    a.print();

    Maker<int,double> b(10,99.9);
    b.print();
    
}