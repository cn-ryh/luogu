//P1307 write by cn_ryh
#include <iostream>
using namespace std;

int main()
{
    string k;
    cin>>k;
    int r = k.length();
    int l = 0;
    if(k[0] == '-')
    {
        l++;
        cout<<"-";
    }
    for(int i = r-1;i>l;i--)
    {
        if(k[i] == '0')
        {
            r--;
        }
        else{
            break;
        }
    }
    for(int i = r-1;i>=l;i--)
    {
        cout<<k[i];
    }
    return 0;
}
