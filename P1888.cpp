// P1888 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    int s[3];
    for(int i = 0; i<=2; i++)
    {
        cin>>s[i];
    }
    for(int i = 0; i<=2; i++)
    {
        for(int j = 0; j<2; j++)
        {
            if(s[j]>s[j+1])
            {
                int flag = s[j];
                s[j] = s[j+1];
                s[j+1] = flag;
            }
        }
    }
    int a = s[0],b = s[1],c=s[2];
    for(int i = 2;i<=a;i++)
    {
        if(a % i == 0 && c % i == 0)
        {
            a /= i;
            c /= i;
        }
    }
    cout<<a<<"/"<<c<<endl;
}
