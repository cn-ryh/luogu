// P1548 write by cn_ryh
#include <cstdio>
using namespace std;
int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    unsigned long long ans1(0),ans2(0);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(i == j)
            {
                ans1 += (n-i+1)*(m-j+1);
            }
            else
            {
                ans2 += (n-i+1)*(m-j+1);
            }
        }
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}