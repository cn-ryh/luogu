// P1089 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int a[12];
    for (int i = 0; i < 12; i++)
    {
        cin >> a[i];
    }
    int num, now;
    num = now = 0;
    for (int i = 0; i < 12; i++)
    {
        now += 300;
        int s;
        s = a[i];
        if (now < s)
        {
            cout << "-" << i + 1 << endl;
            return 0;
        }
        else
        {
            now -= s;
            while (now >= 100)
            {
                now -= 100;
                num += 100;
            }
        }
    }
    cout << now + num * 1.2 << endl;
}