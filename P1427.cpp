// P1427 write by cn_ryh
#include <iostream>

using namespace std;

int main()
{
    int nums[101];
    int flag = 0;
    while(true)
    {
        int k;
        cin>>k;
        if(k!=0)
        {
            nums[flag++] = k;
        }
        else
        {
            break;
        }
    }
    for(int i = flag-1; i>=0; i--)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
