// CF458B write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max(A, B) (A > B) ? (A) : (B)
#define min(A, B) (A < B) ? (A) : (B)
void read(int &p)
{
    p = 0;
    int k = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            k = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        p = p * 10 + c - '0';
        c = getchar();
    }
    p *= k;
    return;
}
void write_(int x)
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
void writesp(int x)
{
    write_(x);
    putchar(' ');
}
void writeln(int x)
{
    write_(x);
    putchar('\n');
}
int n;
int max_x, max_y, min_x, min_y;
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    read(n);
    max_x = max_y = LONG_LONG_MIN;
    min_x = min_y = LONG_LONG_MAX;
    for (int i = 1, x, y; i <= n; i++)
    {
        read(x), read(y);
        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
    }
    int l = max(max_x - min_x, max_y - min_y);
    writeln(l * l);
    return 0;
}