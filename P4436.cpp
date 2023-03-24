// P4436 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_n 1000001
inline void read(int &p)
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
inline void writesp(int x)
{
    write_(x);
    putchar(' ');
}
inline void writeln(int x)
{
    write_(x);
    putchar('\n');
}
int l[max_n], r[max_n], key_[max_n], n, m, p, fa[max_n], vis[max_n];
void dfs(int u)
{
    if (vis[u])
    {
        return;
    }
    vis[u] = 1;
    bool flag;
    // 初始化
    while (true)
    {
        flag = false;
        if (r[u] < n && key_[r[u]] >= l[u] && key_[r[u]] <= r[u])
        {
            dfs(fa[r[u] + 1]);
            r[u] = r[fa[r[u] + 1]];
            flag = 1;
        }
        if (l[u] > 1 && key_[l[u] - 1] >= l[u] && key_[l[u] - 1] <= r[u])
        {
            dfs(fa[l[u] - 1]);
            l[u] = l[fa[l[u] - 1]];
            flag = 1;
        }
        if (!flag)
        {
            break;
        }
    }
}
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    read(n), read(m), read(p);
    register int i(0),pos(0),u(0),v(0);
    for (i = 1; i <= m; ++i)
    {
        read(pos);
        read(key_[pos]);
    }
    // 缩点 with 类并查集
    for (i = 1; i <= n; ++i)
    {
        if (i == 1 || key_[i - 1])
        {
            fa[i] = l[i] = r[i] = i;
        }
        else
        {
            // 合并集合
            fa[i] = fa[i - 1];
            // 更新右端点
            r[fa[i]] = i;
        }
    }
    // 从每一组连通块开始搜索
    for (i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
        {
            dfs(i);
        }
    }
    for (i = 1; i <= p; ++i)
    {
        read(u), read(v);
        // 区间包含了，可以到达
        if (l[fa[u]] <= v && r[fa[u]] >= v)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}