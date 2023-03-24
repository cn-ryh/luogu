// P1161 write by cn_ryh
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    char lights[2000001];
    for (int i = 1; i < 2000001; i++)
    {
        lights[i] = 'a';
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double c;
        int t;
        cin >> c >> t;
        for (int j = 1; j <= t; j++)
        {
            if (lights[int(floor(c * j))] == 'b')
            {
                lights[int(floor(c * j))] = 'a';
            }
            else
            {
                lights[int(floor(c * j))] = 'b';
            }
        }
    }
    for (int i = 1; i < 2000001; i++)
    {
        if (lights[i] == 'b')
        {
            cout << i << endl;
        }
    }
    return 0;
}
