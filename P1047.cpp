// P1047 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
    int l, m;
    cin >> l >> m;
    int trees[l + 1];
    for (int i = 0; i <= l; i++)
    {
        trees[i] = 0;
    }
    int begin, end;
    for (int i = 0; i < m; i++)
    {
        cin >> begin >> end;
        for (int j = begin; j <= end; j++)
        {
            trees[j] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i <= l; i++)
    {
        if (trees[i] == 0)
        {
            sum++;
        }
    }
    cout << sum << endl;
}
