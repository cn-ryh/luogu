// P1179 write by cn_ryh
#include <cstdio>
using namespace std;
int main()
{
    long long l, r;
    scanf("%lld %lld", &l, &r);
    long long result = 0;
    for (long long i = l; i <= r; i++)
    {
        long long k = i;
        while (k > 0)
        {
            if (k % 10 == 2)
            {
                result++;
            }
            k /= 10;
        }
    }
    printf("%lld", result);
    return 0;
}