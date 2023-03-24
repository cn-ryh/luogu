// P1652 write by cn_ryh
#include <cstdio>
#include <cmath>
using namespace std;
struct circle
{
    long long x;
    long long y;
    long long r;
};
bool in(long long x,long long y,long long c_x,long long c_y,long long r)
{
     long long dx = x - c_x;
     long long dy = y - c_y;
     if(pow(dx,2)+pow(dy,2)<pow(r,2))
     {
        return true;
     }
     return false; 
}
int main()
{
    long long n;
    scanf("%lld",&n);
    circle circles[n];
    for(long long i = 0;i<n;i++)
    {
        scanf("%lld",&circles[i].x);
    }
    
    for(long long i = 0;i<n;i++)
    {
        scanf("%lld",&circles[i].y);
    }
    for(long long i = 0;i<n;i++)
    {
        scanf("%lld",&circles[i].r);
    }
    long long x1,y1,x2,y2;
    scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
    long long ans = 0;
    for(long long i = 0;i<n;i++)
    {
        bool b1 = in(x1,y1,circles[i].x,circles[i].y,circles[i].r);
        bool b2 = in(x2,y2,circles[i].x,circles[i].y,circles[i].r);
        if((b1&&!b2)||(!b1&&b2))
        {
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}