// P1720 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define mo 998244353
#define max_n 5000004
#define int long long
inline void read(int &p)
{
    p = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        p = p * 10 + c - '0';
        c = getchar();
    }
    return;
}
inline void write_(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        write_(x / 10);
    }
    putchar(x % 10 + '0');
}
inline void writeln(int x)
{
    write_(x);
    putchar('\n');
}
int ksm(int a, int b)
{
    int res = 1;
    for (; b; b >>= 1, a = (a * a) % mo)
    {
        if (b & 1)
        {
            res = (res * a) % mo;
        }
    }
    return res;
}
int n, t;
int jiecheng[max_n], inv[max_n], g[max_n];
signed main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    jiecheng[0] = 1;
    for (int i = 1; i <= 5000001; i++)
    {
        jiecheng[i] = (jiecheng[i - 1] * i) % mo;
    }
    inv[5000001] = ksm(jiecheng[5000001], mo - 2);
    // 线性逆元
    for (int i = 5000001; i; i--)
    {
        inv[i - 1] = inv[i] * i % mo;
    }
    g[0] = 1, g[1] = 0;
    for (int i = 2; i <= 5000001; i++)
    {
        g[i] = (g[i - 2] * 2 * (i - 1) + g[i - 1]) % mo * 4 % mo * i % mo * (i - 1) % mo;
        g[i] %= mo;
    }
    // writeln(g[3289]);
    read(t);
    for (int p = 1; p <= t; p++)
    {
        read(n);
        for (int m = 0; m <= n; m++)
        {
            int ans = jiecheng[n] * inv[n - m] % mo * jiecheng[n] % mo * inv[m] % mo * inv[n - m] % mo * g[n - m] % mo * ksm(2, m);
            writeln(ans % mo);
            // cout << m << "--" << endl;
        }
    }
    return 0;
}