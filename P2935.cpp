// P2935 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define max_n 580
int n, c, f;
int fs[max_n];
struct node
{
    int dis, v;
    bool operator>(const node n2)
        const
    {
        return this->dis > n2.dis;
    }
};
struct edge
{
    int v, w;
};
vector<edge> e[max_n];
int vis[max_n], dis[max_n];
void dijkstar(int s)
{
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, s});
    while (!que.empty())
    {
        int u = que.top().second;
        que.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                que.push({dis[v], v});
            }
        }
    }
}
int main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d %d %d", &n, &f, &c);
    for (int i = 1; i <= f; i++)
    {
        scanf("%d", &fs[i]);
    }
    for (int i = 1; i <= c; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    int res = -1, min_n = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        dijkstar(i);
        int th = 0;
        for (int j = 1; j <= f; j++)
        {
            th += dis[fs[j]];
        }
        if (th < min_n)
        {
            res = i;
            min_n = th;
        }
    }
    printf("%d\n", res);
    return 0;
}