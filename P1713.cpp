// P1713 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_n 52
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
int n, m;
int mp[max_n][max_n], vis[max_n][max_n];
int max_len, min_len;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
void bfs()
{
    pair<int, int> way[max_n << 3]; // 路径
    int l = 1, r = 1;
    way[1] = {1, 1};
    vis[1][1] = 1;
    while (l <= r)
    {
        int jr = r;
        for (int i = l; i <= jr; i++)
        {
            int x = way[i].first, y = way[i].second; // 当前位置
            for (int j = 0; j < 4; j++)
            {
                int new_x = x + dx[j], new_y = y + dy[j]; // 下一步的位置
                if (mp[new_x][new_y] && !vis[new_x][new_y] && new_x <= n && new_x >= 1 && new_y <= n && new_y >= 1)
                {
                    ++r;
                    way[r] = {new_x, new_y};
                    vis[new_x][new_y] = 1;
                }
            }
        }
        l = jr + 1;
        min_len++;
        if (vis[n][n]) // 到达终点
        {
            return;
        }
    }
    min_len = -1;
}
struct DP
{
    int o[max_n << 14], g[max_n << 14];
    int tp;
} dp[2]; // 滚动数组求解节省空间
int Hash[max_n << 14];
void put(int k, int gs, int y)
{
    if (y == n) // 在行末需要特判
    {
        if (k & 3)
        {
            return;
        }
        k >>= 2;
    }
    int ps = Hash[k];
    if (!ps) // 位置空
    {
        dp[1].tp++;
        ps = Hash[k] = dp[1].tp;
        dp[1].o[ps] = k;
        dp[1].g[ps] = gs;
    }
    else // 位置不空取最大值
    {
        dp[1].g[ps] = max(dp[1].g[ps], gs);
    }
}
void update(int &k, int vs, int st)
{
    int back[max_n], new__k = k;
    int tp_ = 0;
    for (int i = n + 1; i > 0; --i)
    {
        back[i] = (new__k & 3);
        new__k >>= 2;
    }
    if (vs == 1)
    {
        for (int i = st + 2; i <= n + 1; i++)
        {
            if (back[i] == 1)
            {
                tp_++;
            }
            else if (back[i] == 2)
            {
                if (tp_)
                {
                    --tp_;
                }
                else
                {
                    k -= (1 << ((n - i + 1) << 1));
                    return;
                }
            }
        }
    }
    else
    {
        for (int i = st - 1; i > 0; i--)
        {
            if (back[i] == 2)
            {
                ++tp_;
            }
            else if (back[i] == 1)
            {
                if (tp_)
                {
                    --tp_;
                }
                else
                {
                    k += (1 << ((n - i + 1) << 1));
                    return;
                }
            }
        }
    }
}
void make_ans(int x, int y)
{
    int l = 3 << ((n - y + 1) << 1), u = l >> 2;
    while (dp[0].tp)
    {
        int k = dp[0].o[dp[0].tp], gs = dp[0].g[dp[0].tp];
        dp[0].tp--;
        int nl = (k & l), nu = (k & u);
        k -= nl + nu;
        //  cout<<"%"<<k<<endl;

        nl >>= ((n - y + 1) << 1), nu >>= ((n - y) << 1);
        if (!(nu | nl)) // 上面左面都没有插头
        {
            put(k, gs, y); // 空
            if (mp[x][y])  // 判断是否能走
            {
                put(k | (u << 1), gs + 1, y); // 走
            }
        }
        else if (mp[x][y] == 0) // 不可走
        {
            continue;
        }
        else if (nu > 0 && nl > 0) // 上左都有插头
        {
            if (nu == nl)
            {
                int new_k = k;
                update(new_k, nu, y);
                put(new_k, gs + 1, y);
            }
            else if (nu == 1)
            {
                put(k, gs + 1, y);
            }
            else
            {
                continue;
            }
        }
        else // 有一个地方有插头
        {
            int ad = (nu | nl);
            // 分别从右侧和下侧连接
            put(k | (ad << ((n - y) << 1)), gs + 1, y);
            put(k | (ad << ((n - y + 1) << 1)), gs + 1, y);
        }
    }
    dp[0] = dp[1]; // 滚动数组
    while (dp[1].tp)
    {
        Hash[dp[1].o[dp[1].tp--]] = 0; // 清空Hash
    }
}
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    read(n), read(m);
    // 初始化地图
    memset(mp, 1, sizeof(mp));

    for (int i = 1, x, y; i <= m; i++)
    {
        read(x), read(y);
        mp[n - x + 1][y] = 0; // 翻转地图，设置障碍物
    }
    bfs();
    dp[1].tp = 0, dp[0].tp = 2;
    dp[0].o[1] = (1 << (n << 1));
    dp[0].g[1] = dp[0].g[2] = 1;
    dp[0].o[2] = (1 << ((n - 1) << 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                continue; // 跳过第一个初始化的点
            }
            if (i == n && j == n)
            {
                break; // 到达终点
            }
            make_ans(i, j);
        }
    }
    for (int i = 1; i <= dp[0].tp; i++)
    {
        if (dp[0].o[i] == 1 || dp[0].o[i] == 4)
        {
            max_len = max(max_len, dp[0].g[i]);
            //   writeln(max_len);
        }
    }
    // writeln(max_len);
    // writeln(min_len);
    writeln(max_len - min_len);
    return 0;
}