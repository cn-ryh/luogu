// B2011 write by cn_ryh
#include <iostream>
#include <cstdio>
using namespace std;
int a_and_b(int a, int b, int c)
{
    return (a + b) / c;
}
int main()
{
    double a;
    double b;
    cin >> a >> b;
    printf("%.9lf", a / b);

    return 0;
}
