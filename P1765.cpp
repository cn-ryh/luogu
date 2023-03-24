// P1765 write by cn_ryh
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int nums[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    string s;
    getline(cin,s);
    int l = s.length();
    int ans = 0;
    for(int i = 0;i<l;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            ans+=nums[s[i]-97];
        }
        else if(s[i] == ' ')
        {
            ans++;
        }
    }
    cout<<ans;
}