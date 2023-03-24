// P1567 write by cn_ryh
#include <cstdio>
using namespace std;
int main()
{
    long long n;
    scanf("%lld", &n);
    long long t[n];
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &t[i]);
    }
    long long max_n = 0, now_t = t[0], now_time = 1;
    for (long long i = 1; i < n; i++)
    {
        if (t[i] > now_t)
        {
            now_t = t[i];
            now_time++;
        }
        else
        {
            max_n = max_n > now_time ? max_n : now_time;
            now_t = t[i];
            now_time = 1;
        }
    }
    max_n = max_n > now_time ? max_n : now_time;
    now_t = 0;
    now_time = 0;
    printf("%lld", max_n);
}