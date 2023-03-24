// P1597 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length();
    int a,b,c;
    a = b = c = 0;
    for(int i=1;i<=l/5;i++)
    {
        char p1 = s[5*i-5];
        char p2 = s[5*i-2];
        if(p2>=48 && p2<=57)
        {
            switch (p1)
            {
            case 'a':
                a = p2-48;
                break;
            case 'b':
                b = p2-48;
                break;
            case 'c':
                c = p2-48;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (p1)
            {
            case 'a':
                switch (p2)
                {
                case 'a':
                    a = a;
                    break;
                case 'b':
                    a = b; 
                    break;
                case 'c':
                    a = c;
                    break;
                default:
                    break;
                }
                break;
            case 'b':
                switch (p2)
                {
                case 'a':
                    b = a;
                    break;
                case 'b':
                    b = b;
                    break;
                case 'c':
                    b = c;
                    break;
                default:
                    break;
                }
                break;
            case 'c':
                switch (p2)
                {
                case 'a':
                    c = a;
                    break;
                case 'b':
                    c = b;
                    break;
                case 'c':
                    c = c;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}