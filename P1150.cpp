// P1150 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int f = 0;
    int t = 0;
    while (n > 0)
    {
        t++;
        n--;
        f++;
        if (f == k)
        {
            n++;
            f = 0;
        }
    }
    cout << t << endl;
    return 0;
}