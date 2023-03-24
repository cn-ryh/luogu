// P1059 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int b[a];
    for (int i = 0; i < a; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 1; j < a; j++)
        {
            if (b[j - 1] > b[j])
            {
                int flag = b[j];
                b[j] = b[j - 1];
                b[j - 1] = flag;
            }
        }
    }
    int flag = -1;
    int t = 0;
    for (int i = 0; i < a; i++)
    {
        if (b[i] != flag)
        {
            flag = b[i];
            t++;
        }
        else
        {
            b[i] = -1;
        }
    }
    cout << t << endl;
    for (int i = 0; i < a; i++)
    {
        if (b[i] != -1)
        {
            cout << b[i] << " ";
        }
    }
}