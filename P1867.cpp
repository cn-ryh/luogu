// P1867 write by cn_ryh
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	double blood = 10;
	int exp = 0,level = 0;
	double x;
	int a;
	x =  0;
	a = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>x>>a;
		if(x <= 0)
		{
			if(blood - x > 10)
			{
				blood = 10;
			}
			else
			{
				blood -= x;
			}
			exp+=a;
		}
		else
		{
			if(blood - x>0)
			{
				blood -= x;
				exp += a;
			}
			else
			{
				printf("%d %d",level,exp);
				return 0;
			}
		}
		while(true)
		{
			if(exp>=pow(2,level))
			{
				exp -= pow(2,level);
				level++;
			} 
			else
			{
			break;
			}
		}
	}
	printf("%d %d",level,exp);
	return 0;
} 