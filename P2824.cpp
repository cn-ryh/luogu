// P2824 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_n 100100
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
struct QUERY
{
    int op, l, r;
} ques[max_n];
int n, m, __k;
int w[max_n];
struct node
{
    int val, lazy;
} tree[max_n << 2];
void pushdown(int k, int l, int r)
{
    if (tree[k].lazy)
    {
        int mid = (l + r) >> 1;
        if (tree[k].lazy == 1)
        {
            tree[k << 1].val = mid - l + 1;
            tree[(k << 1) | 1].val = r - mid;
        }
        else
        {
            tree[k << 1].val = 0;
            tree[(k << 1) | 1].val = 0;
        }
        tree[k << 1].lazy = tree[(k << 1) | 1].lazy = tree[k].lazy;
        tree[k].lazy = 0;
    }
}
void build(int k, int l, int r, int check_mid)
{
    if (l == r)
    {
        tree[k].val = (w[l] >= check_mid);
        tree[k].lazy = 0; // 清零
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid, check_mid);
    build((k << 1) | 1, mid + 1, r, check_mid);
    tree[k].val = tree[k << 1].val + tree[(k << 1) | 1].val;
    tree[k].lazy = 0;
}
void update(int k, int l, int r, int ul, int ur, int val)
{
    if (ul > r || ur < l)
    {
        return;
    }
    if (ul <= l && ur >= r)
    {
        tree[k].val = val * (r - l + 1);
        tree[k].lazy = 1;
        if (!val)
        {
            tree[k].lazy = -tree[k].lazy;
        }
        return;
    }
    pushdown(k, l, r);
    int mid = (l + r) >> 1;
    update(k << 1, l, mid, ul, ur, val);
    update((k << 1) | 1, mid + 1, r, ul, ur, val);
    tree[k].val = tree[k << 1].val + tree[(k << 1) | 1].val;
}
int query(int k, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r)
    {
        return 0;
    }
    if (ql <= l && qr >= r)
    {
        return tree[k].val;
    }
    pushdown(k, l, r);
    int mid = (l + r) >> 1;
    return query(k << 1, l, mid, ql, qr) + query((k << 1) | 1, mid + 1, r, ql, qr);
}
bool checker(int md)
{
    build(1, 1, n, md);
    //   puts("#1");
    for (int i = 1; i <= m; i++)
    {
        int num_of_one = query(1, 1, n, ques[i].l, ques[i].r);
        // puts("#2");
        if (ques[i].op)
        {
            update(1, 1, n, ques[i].l, ques[i].l + num_of_one - 1, 1);
            update(1, 1, n, ques[i].l + num_of_one, ques[i].r, 0);
            //      puts("#3");
        }
        else
        {
            update(1, 1, n, ques[i].r - num_of_one + 1, ques[i].r, 1);
            update(1, 1, n, ques[i].l, ques[i].r - num_of_one, 0);
            // puts("#3");
        }
    }
    // puts("#4");
    return query(1, 1, n, __k, __k);
}
int solution(int l, int r)
{
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        //    writesp(l), writeln(r);
        if (checker(mid))
        {
            ans = mid, l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
signed main()
{
#if _clang_
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    read(n), read(m);
    for (int i = 1; i <= n; i++)
    {
        read(w[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        read(ques[i].op);
        read(ques[i].l), read(ques[i].r);
    }
    read(__k);
    writeln(solution(1, n));
    return 0;
}