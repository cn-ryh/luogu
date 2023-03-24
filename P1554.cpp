// P1554 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    unsigned long long n,m;
    cin>>n>>m;
    long long times[10];
    for(int i = 0;i<10;i++)
    {
        times[i] = 0;
    }
    for(unsigned long long i = n;i<=m;i++)
    {
        unsigned long long s = i;
        while(s>0)
        {
            times[s%10]++;
            s/=10;
        }
    }
    for(int i = 0;i<10;i++)
    {
        cout<<times[i]<<" ";
    }
    return 0;
}
