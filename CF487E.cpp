// CF487E write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_n 300000
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
int n, m, q;
int w[max_n];
int head[max_n], tot;
void add(int u, int v)
{
    edge[++tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}
int dfn[max_n], low[max_n], timer = 0;
int st[max_n];
vector<int> G[max_n];
int node_cnt;
void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    st[++st[0]] = u;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == dfn[u])
            {
                int now;
                ++node_cnt;

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
int fa[max_n], siz[max_n], dep[max_n], top[max_n], son[max_n];
void dfs1(int u, int fat)
{
    dep[u] = dep[fat] + 1;
    siz[u] = 1;
    fa[u] = fat;
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
int dfn_[max_n], rev[max_n], tim;
void dfs2(int u, int t)
{
    dfn_[u] = ++tim;
    rev[tim] = u;
    top[u] = t;
    if (son[u])
    {
        dfs2(son[u], t);
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
namespace SegmentTree
{
#define lc (k << 1)
#define rc ((k << 1) | 1)
#define mid ((l + r) >> 1)
    int tree[max_n << 2];
    void build(int k, int l, int r)
    {
        if (l == r)
        {
            tree[k] = w[rev[l]];
            return;
        }
        build(lc, l, mid);
        build(rc, mid + 1, r);
        tree[k] = min(tree[lc], tree[rc]);
    }
    void update(int k, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[k] = val;
            return;
        }
        if (pos <= mid)
        {
            update(lc, l, mid, pos, val);
        }
        else
        {
            update(rc, mid + 1, r, pos, val);
        }
        tree[k] = min(tree[lc], tree[rc]);
    }
    int query(int k, int l, int r, int ql, int qr)
    {
        if (r < ql || l > qr)
        {
            return INT_MAX;
        }
        if (ql <= l && qr >= r)
        {
            return tree[k];
        }
        return min(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
    }
#undef lc
#undef rc
#undef mid
}
multiset<int> S[max_n];
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    read(n), read(m), read(q);
    for (int i = 1; i <= n; i++)
    {
        read(w[i]);
    }
    node_cnt = n;
    for (int i = 1, u, v; i <= m; i++)
    {
        read(u), read(v);
        add(u, v);
        add(v, u);
    }
    tarjan(1);
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (fa[i])
        {
            S[fa[i]].insert(w[i]);
        }
    }
    for (int i = n + 1; i <= node_cnt; i++)
    {
        w[i] = *S[i].begin();
    }
    SegmentTree::build(1, 1, node_cnt);
    char op;
    for (int i = 1, u, v; i <= q; i++)
    {
        cin >> op;
        read(u), read(v);
        if (op == 'C')
        {
            SegmentTree::update(1, 1, node_cnt, dfn_[u], v);
            if (fa[u])
            {
                int f = fa[u];
                S[f].erase(S[f].lower_bound(w[u]));
                S[f].insert(v);
                if (w[f] != *S[f].begin())
                {
                    w[f] = *S[f].begin();
                    SegmentTree::update(1, 1, node_cnt, dfn_[f], w[f]);
                }
            }
            w[u] = v;
        }
        else
        {
            int ans = 0x3fffffff;
            while (top[u] != top[v])
            {
                if (dep[top[u]] < dep[top[v]])
                {
                    swap(u, v);
                }
                ans = min(ans, SegmentTree::query(1, 1, node_cnt, dfn_[top[u]], dfn_[u]));
                u = fa[top[u]];
            }
            if (dfn_[u] > dfn_[v])
            {
                swap(u, v);
            }
            ans = min(ans, SegmentTree::query(1, 1, node_cnt, dfn_[u], dfn_[v]));
            if (u > n)
            {
                ans = min(ans, w[fa[u]]);
            }
            writeln(ans);
        }
    }
    return 0;
}