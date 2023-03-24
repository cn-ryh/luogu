//P1321 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length();
    int boys,girls;
    boys = girls = 0;
    for(int i = 0;i<l - 2;i++)
    {
        if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y')
        {
            boys++;
        }
    }
    for(int i = 0;i<l - 3;i++)
    {
        if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l')
        {
            girls++;
        }
    }
    cout<<boys<<endl<<girls<<endl;
    return 0;
}