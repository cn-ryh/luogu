// P1614 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int nums[n];
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }
    int min_n = 9999999999;
    for(int i = 0;i<=n-m;i++)
    {
        int flag = 0;
        for(int j = i;j<i+m;j++)
        {
            flag += nums[j];

        }
        min_n = min(min_n,flag);
    }
    cout<<min_n<<endl;
    return 0;
}
