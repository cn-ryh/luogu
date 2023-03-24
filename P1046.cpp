// P1046 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    int flag = 0;
    int h;
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cin >> h;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] <= h + 30)
        {
            flag++;
        }
    }
    cout << flag;
    return 0;
}
