// P3995 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
int m[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int n, q;
int b[1005];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(b, b + n);
    while (q--)
    {
        int l, t;
        scanf("%d%d", &l, &t);
        int a = -1;
        for (int i = 0; i < n; i++)
        {
            int g = b[i] % m[l];
            if (g == t)
            {
                a = b[i];
                break;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}