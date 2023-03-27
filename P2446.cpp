// P2446 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define max_n 3001
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
vector<pair<int, int>> G1[max_n];
vector<int> G2[max_n];
int n, m;
int into[max_n], vis[max_n], dis[max_n], rel[max_n], du[max_n];
void dijkstra()
{
    memset(dis, 0x7f, (n + 1) * sizeof(int));
    memset(rel, 0x7f, (n + 1) * sizeof(int));
    dis[1] = into[1] = rel[1] = 0;
    du[1] = 0;
    register priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 1});
    while (!que.empty())
    {
        int u = que.top().second;
        que.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto e : G1[u])
        {
            int v = e.first, w = e.second;
            if (rel[v] > dis[u] + w)
            {
                rel[v] = dis[u] + w;
                if (!du[v])
                {
                    dis[v] = max(into[v], rel[v]);
                    que.push({dis[v], v});
                }
            }
        }
        for (auto v : G2[u])
        {
            into[v] = max(into[v], dis[u]);
            du[v]--;
            if (!du[v])
            {
                dis[v] = max(rel[v], into[v]);
                que.push({dis[v], v});
            }
        }
    }
}
signed main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    read(n), read(m);
    register int u, v, w, i;
    for (i = 1; i <= m; ++i)
    {
        read(u), read(v), read(w);
        G1[u].push_back({v, w});
    }
    for (i = 1; i <= n; ++i)
    {
        read(u);
        for (w = 1; w <= u; ++w)
        {
            read(v);
            G2[v].push_back(i);
            du[i]++;
        }
    }
    dijkstra();
    writeln(dis[n]);
    return 0;
}