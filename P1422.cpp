// P1422 write by cn_ryh
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double flag;
	for(int i = 1;i<=n;i++)
	{
		if(i<=150)
		{
			flag+=0.4463;		
		}
		else if(i<=400)
		{
			flag+=0.4663;
		}
		else
		{
			flag+=0.5663;
		}
	}
	printf("%.1f",flag);
}