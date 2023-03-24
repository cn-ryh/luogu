// P4320 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_n 4000001
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
int fa[max_n], low[max_n], son[max_n], siz[max_n], dep[max_n], top[max_n], dfn[max_n];
struct node
{
    int to, nxt;
} edge[max_n];
int head[max_n], tot;
int n, m, point_cnt;
int timer;
void add(int u, int v)
{
    edge[++tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}
int st[max_n], tp;
vector<int> G[max_n];
void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    st[++tp] = u;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                G[u].push_back(++point_cnt);
                G[point_cnt].push_back(u);
                int now;
                while (now != v)
                {
                    now = st[tp--];
                    G[point_cnt].push_back(now);
                    G[now].push_back(point_cnt);
                }
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void dfs1(int u, int d)
{
    siz[u] = 1;
    dep[u] = d;
    for (auto v : G[u])
    {
        if (dep[v])
        {
            continue;
        }
        fa[v] = u;
        dfs1(v, d + 1);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
        {
            son[u] = v;
        }
    }
}
void dfs2(int u, int t)
{
    top[u] = t;
    if (son[u])
    {
        dfs2(son[u], t);
    }
    for (auto v : G[u])
    {
        if (v == fa[u] || v == son[u])
        {
            continue;
        }
        dfs2(v, v);
    }
}
int get_lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] > dep[top[v]])
        {
            u = fa[top[u]];
        }
        else
        {
            v = fa[top[v]];
        }
    }
    return (dep[u] < dep[v]) ? (u) : (v);
}
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    read(n), read(m);
    point_cnt = n;
    for (int i = 1, u, v; i <= m; i++)
    {
        read(u), read(v);
        add(u, v);
        add(v, u);
    }
    tarjan(1);
    dfs1(1, 1);
    dfs2(1, 1);
    int q;
    read(q);
    for (int i = 1, u, v; i <= q; i++)
    {
        read(u), read(v);
        int lca_ = get_lca(u, v);
        writeln((dep[u] + dep[v] - 2 * dep[lca_]) / 2 + 1);
    }
    return 0;
}