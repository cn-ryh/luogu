// B2012 write by cn_ryh
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double a;
    double b;
    cin >> a >> b;
    b = b * 100.0;
    printf("%.3f", b / a);
    cout << "%" << endl;
    return 0;
}
