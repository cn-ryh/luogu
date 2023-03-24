//B2043 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    bool k = true;
    if(x%3 == 0)
    {
        cout<<3<<" ";
        k = false;
    }
    if(x%5 == 0)
    {
        cout<<5<<" ";
        k = false;
    }
    if(x%7 == 0)
    {
        k = false;
        cout<<7<<" ";
    }
    if(k)
    {
        cout<<"n"<<endl;
    }
    
    return 0;
}