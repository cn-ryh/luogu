//B2010 write by cn_ryh
#include <iostream>
using namespace std;
int a_and_b(int a,int b,int c)
{
    return (a+b)/c;
}
int main() {
    int a;
    int b;
    cin>>a>>b;
    cout<<a/b<<" "<<a%b<<endl;
    return 0;
}
