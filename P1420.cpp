//P1420 write by cn_ryh
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
    int mf,tf;
    mf = 0;
    tf = 1;
    for(int i = 0;i<n-1;i++)
    {
        if(nums[i+1] == nums[i]+1)
        {
            tf++;
        }
        else
        {
            mf = max(mf,tf);
            tf = 1;
        }
    }
    mf = max(mf,tf);
    cout<<mf<<endl;
    return 0;
}
