//B2007 write by cn_ryh
#include <iostream>
using namespace std;
int a_and_b(int a,int b)
{
    return a+b;
}
int main() {
    int a;
    int b;
    cin>>a>>b;
    cout<<a_and_b(a,b)<<endl;
    return 0;
}
