// P1200 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();
    int numsa, numsb;
    numsa = numsb = 1;
    for (int i = 0; i < la; i++)
    {
        numsa *= a[i] - 64;
    }
    numsa %= 47;
    for (int i = 0; i < lb; i++)
    {
        numsb *= b[i] - 64;
    }
    numsb %= 47;
    if (numsa == numsb)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
}