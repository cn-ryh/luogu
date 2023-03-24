// B3652 write by cn_ryh
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    unsigned long long height[n];
    unsigned long long max_n = 0, min_n = 999999999999999999;
    for (long long i = 0; i < n; i++)
    {
        cin >> height[i];
        max_n = max(max_n, height[i]);
        min_n = min(min_n, height[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << max_n - height[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << height[i] - min_n << " ";
    }
    cout << endl;
    return 0;
}