// P1035 write by cn_ryh
#include <iostream>
using namespace std;
int main()
{
	int k;
	cin>>k;
	double sum = 0.0;
	long long n;
	for(n = 1;sum<=k;n++)
	{
		sum+=1.00/n;
	}
	cout<<n-1<<endl;
}