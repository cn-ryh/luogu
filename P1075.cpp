//P1075 write by cn_ryh
#include <iostream>
#include <cmath>
using namespace std;
bool s(long long n)
{
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	long long n;
	cin>>n;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i == 0 && s(i))
		{
			cout<<n/i<<endl;
		}
	}
}