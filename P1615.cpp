// P1615 write by cn_ryh

#include <iostream>

using namespace std;
int main()
{
    long long a,b,c,d,e,f;
    char k;
    cin>>a>>k>>b>>k>>c>>d>>k>>e>>k>>f;
    int s;
    cin>>s;
    cout<<((d-a)*3600+(e-b)*60+(f-c))*s<<endl;
    return 0;
}