//P1320 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    string thi;
    string nums = "";
    cin>>thi;
    nums+=thi;
    n = thi.length();
    for(int i = 2; i<=n; i++)
    {
        cin>>thi;
        nums+=thi;
    }
    int l = nums.length();
    char pas ='0';
    int flag = 0;
    cout<<n<<" ";
    for(int i = 0; i<l; i++)
    {
        if(nums[i] == pas)
        {
            flag++;
        }
        else
        {
            cout<<flag<<" ";
            flag=1;
            if(pas == '0')
            {
                pas = '1';
            }
            else
            {
                pas = '0';
            }
        }
    }
    cout<<flag;
}
