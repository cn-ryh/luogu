// P3761 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_n 10100
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
struct E
{
    int u, v, w;
} es[max_n];
struct node
{
    int to, nxt, val;
} edge[max_n];
int head[max_n], tot;
void add(int u, int v, int w)
{
    edge[++tot].to = v;
    edge[tot].nxt = head[u];
    edge[tot].val = w;
    head[u] = tot;
}
int n;
int vis[max_n];
int dis1[max_n], dis2[max_n], mx[max_n];
int dis;
void find_d(int u) // 找直径
{
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to, w = edge[i].val;
        if (vis[v])
        {
            continue;
        }
        find_d(v);
        // dis1最长，dis2次长
        int val = dis1[v] + w;
        if (val > dis1[u])
        {
            dis2[u] = dis1[u];
            dis1[u] = val;
            mx[u] = v; // 长链位置
        }
        else if (val > dis2[u])
        {
            dis2[u] = val;
        }
    }
    dis = max(dis, dis1[u] + dis2[u]);
}
int rad;
void find_r(int u, int fa_r)
{
    rad = min(rad, max(fa_r, dis1[u]));
    vis[u] = 0;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to, w = edge[i].val;
        if (vis[v])
        {
            if (v == mx[u])
            {
                find_r(v, max(dis2[u], fa_r) + w);
            }
            else
            {
                find_r(v, max(dis1[u], fa_r) + w);
            }
        }
    }
}
void init()
{
    rad = 0x7ffffffffffff;
    memset(dis1, 0, (n + 1) * sizeof(int));
    memset(dis2, 0, (n + 1) * sizeof(int));
    memset(mx, 0, (n + 1) * sizeof(int));
    memset(vis, 0, (n + 1) * sizeof(int));
    dis = 0;
}
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    read(n);
    for (int i = 1; i < n; i++)
    {
        read(es[i].u), read(es[i].v), read(es[i].w);
        add(es[i].u, es[i].v, es[i].w);
        add(es[i].v, es[i].u, es[i].w);
    }
    int res = 0x7ffffffffffff;
    for (int i = 1; i < n; i++) // 枚举删除的高速公路。
    {
        // 分别求出直径和半径
        init();

        int d1, d2, r1, r2;
        vis[es[i].v] = 1;
        find_d(es[i].u);
        d1 = dis;
        dis = 0;
        find_d(es[i].v);
        d2 = dis;
        vis[es[i].v] = 0;
        find_r(es[i].u, 0);
        r1 = rad;
        rad = 0x7ffffffffffff;
        find_r(es[i].v, 0);
        r2 = rad;                                            // 求半径
        res = min(res, max(max(d1, d2), r1 + r2 + es[i].w)); // 更新答案
    }
    writeln(res);
    return 0;
}