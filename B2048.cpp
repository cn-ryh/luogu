//B2048 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int n;
    char c;
    cin>>n>>c;
    int res = 0;
    res+=8;

    if(n>1000)
    {
        if(n%500 == 0)
        {
            res += ((n/500)-2)*4;
        }
        else
        {
            res += ((n/500)-1)*4;
        }
    }
    if(c == 'y')
    {
        res+=5;
    }
    cout<<res<<endl;
}