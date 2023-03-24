// B2049 write by cn_ryh
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(max(a, b), c) << endl;
}