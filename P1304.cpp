// P1304 write by cn_ryh
#include <iostream>
#include <cmath>
using namespace std;
bool zhi(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    cout << "4=2+2" << endl;
    for (int i = 6; i <= n; i += 2)
    {
        for (int j = 3; j < i; j += 2)
        {
            if (zhi(j) && zhi(i - j))
            {
                cout << i << "=" << j << "+" << i - j << endl;
                break;
            }
        }
    }
}