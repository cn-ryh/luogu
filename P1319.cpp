//P1319 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    int s = a*a;
    int fs = 0;
    int q;
    int thi = 0;
    int flag = 0;
    while(fs<s)
    {
        cin>>q;
        fs+=q;
        for(int i = 0;i<q;i++)
        {
            cout<<thi;
            flag++;
            if(flag % a == 0)
            {
                cout<<endl;
            }
        }
        thi = !thi;
    }
    return 0;
}
