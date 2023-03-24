// B2147 write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double x;
    int n;
    cin >> x >> n;
    // printf("%lf %lf",x,n);
    double ans = x;
    for (int i = 1; i <= n; i++)
    {
        ans = sqrt(ans + i);
    }
    printf("%.2lf", ans);
    return 0;
}