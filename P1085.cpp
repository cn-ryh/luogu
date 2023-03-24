//P1085 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
	int a[7][2];
	int b[7];
	for(int i = 0;i<7;i++)
	{
		for(int j = 0;j<2;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 0;i<7;i++)
	{
		b[i] = a[i][0]+a[i][1] - 8;
	}
	int maxn = 0;
	int temp = 0;
	for(int i = 0;i<7;i++)
	{
		if(b[i]>maxn)
		{
			maxn = b[i];
			temp = i+1;
		}
	}
	cout<<temp;
}