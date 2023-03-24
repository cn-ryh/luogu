// P1428 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int nums[n];
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }
    int res[n];
    for(int i = 0;i<n;i++)
    {
        res[i] = 0;
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                res[i]++;
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}
