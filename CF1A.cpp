// CF1A write by cn_ryh
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, m, n;
    cin >> n >> m >> a;
    printf("%lld", (long long)ceil(n / a) * (long long)ceil(m / a));
    return 0;
}