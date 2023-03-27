// P4606 write by cn_ryh
#include <bits/stdc++.h>
#define max_n 500001
using namespace std;
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
struct node
{
    int to, nxt;
} edge[max_n << 1];
int head[max_n], tot;
int T, n, m, q;
void add(int u, int v)
{
    edge[++tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}
vector<int> G[max_n];
int st[max_n];
int low[max_n], siz[max_n], dfn[max_n], timer, dep[max_n], son[max_n], fa[max_n], top[max_n];
int node_cnt;
int dis[max_n];
void tarjan(int u)
{
    st[++st[0]] = u;
    dfn[u] = low[u] = ++timer;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == dfn[u])
            {
                ++node_cnt;
                int now;
                while (now != v)
                {
                    now = st[st[0]--];
                    G[node_cnt].push_back(now);
                    G[now].push_back(node_cnt);
                }
                G[node_cnt].push_back(u);
                G[u].push_back(node_cnt);
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int timer_;
void dfs1(int u, int fat)
{
    fa[u] = fat;
    dep[u] = dep[fat] + 1;
    siz[u] = 1;
    dfn[u] = ++timer_;
    dis[u] = dis[fat] + (u <= n);
    for (auto v : G[u])
    {
        if (v == fat)
        {
            continue;
        }
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
        {
            son[u] = v;
        }
    }
}
void dfs2(int u, int tp)
{
    top[u] = tp;

    if (son[u])
    {
        dfs2(son[u], tp);
    }
    for (auto v : G[u])
    {
        if (v == son[u] || v == fa[u])
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
    return (dep[u] > dep[v]) ? (v) : (u);
}
signed main()
{
    // freopen("1.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    read(T);
    while (T--)
    {

        timer = 0;
        tot = 0;
        read(n), read(m);
        memset(head, 0, sizeof(head));
        memset(son, 0, sizeof(son));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(st, 0, sizeof(st));
        memset(dis, 0, sizeof(dis));
        node_cnt = n;
        for (int i = 1; i <= 2 * n + 10; i++)
        {
            G[i].clear();
        }
        for (int i = 1, u, v; i <= m; i++)
        {
            read(u), read(v);
            add(u, v);
            add(v, u);
        }
        tarjan(1);
        memset(dfn, 0, sizeof(dfn));
        timer_ = 0;
        dfs1(1, 0);
        dfs2(1, 1);
        read(q);
        for (int i = 1; i <= q; i++)
        {
            int S, points[max_n];
            read(S);
            int ans = -2 * S;
            for (int j = 1; j <= S; j++)
            {
                read(points[j]);
            }
            sort(points + 1, points + S + 1, [](int a, int b)
                 { return dfn[a] < dfn[b]; });
            for (int j = 1; j <= S; j++)
            {
                int u = points[j], v = points[j % S + 1];
                ans += dis[u] + dis[v] - 2 * dis[get_lca(u, v)];
            }
            if (get_lca(points[1], points[S]) <= n)
            {
                ans += 2;
            }
            writeln(ans / 2);
            // puts("");
        }
    }
    return 0;
}