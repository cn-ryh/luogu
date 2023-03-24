//P1116 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[10000];
	int step = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int flag = a[j];
				a[j] = a[j+1];
				a[j+1] = flag;
				step++;
				
			}
		 } 
	}
	cout<<step<<endl;
} 