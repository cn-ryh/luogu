//B2009 write by cn_ryh
#include <iostream>
using namespace std;
int a_and_b(int a,int b,int c)
{
    return (a+b)/c;
}
int main() {
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    cout<<a_and_b(a,b,c)<<endl;
    return 0;
}
