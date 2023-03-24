// B3650 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i;
        cout << ans << "\n";
    }
    return 0;
}