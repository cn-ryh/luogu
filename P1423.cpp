// P1423 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    double s = 0;
    double step = 2.0;
    double n;
    cin>>n;
    int flag = 0;
    while(s<n)
    {
        flag++;
        s+=step;
        step*=0.98;
    }
    cout<<flag<<endl;
    return 0;
}
