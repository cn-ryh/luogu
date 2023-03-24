// B2110 write by cn_ryh
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    int b[30] = {0};
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        int c = a[i] - 'a';
        b[c]++;
    }

    for (int i = 0; i < a.length(); i++)
    {
        if (b[a[i] - 'a'] == 1)
        {
            cout << a[i];
            return 0;
        }
    }
    cout << "no";
    return 0;
}
