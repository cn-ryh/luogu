// P1720 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    long long n[49];
    n[0] = 0;
    n[1] = 1;
    n[2] = 1;
    for(int i = 3;i<=48;i++)
    {
        n[i] = n[i-1]+n[i-2];
    }
    int k;
    cin>>k;
    cout<<n[k]<<".00"<<endl;
    return 0;
}
