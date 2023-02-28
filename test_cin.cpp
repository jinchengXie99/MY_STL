#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
    double a = 199.99999;
    cout << setw(20) << setfill('*') << setiosflags(ios::left) << hex << setprecision(10)<< a;   
}