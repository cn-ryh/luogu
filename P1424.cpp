// P1424 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    unsigned long long res = 0;
    int x,n;
    cin>>x>>n;
    int flag = x;
    for(int i = 1;i<=n;i++)
    {
        if(flag != 6 && flag != 7)
        {
            res+=250;
        }
        flag++;
        if(flag>7)
        {
            flag = 1;
        }
    }
    cout<<res<<endl;
    return 0;
}
