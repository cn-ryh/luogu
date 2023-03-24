//P1151 write by cn_ryh
#include <iostream>
using namespace std;
bool get(int n,int k)
{
    int s1 = n%1000;
    int s2 = n/10%1000;
    int s3 = n/100%1000;
    if(s1%k == 0&&s2%k == 0&&s3%k == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    int k;
    cin>>k;
    bool flag = false;
    for(int i = 10000;i<=30000;i++)
    {
        if(get(i,k))
        {
            cout<<i<<endl;
            flag = true;
        }
    }
    if(flag == false)
    {
    	cout<<"No"<<endl;
	}
}