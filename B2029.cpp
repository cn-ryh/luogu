//B2029 write by cn_ryh
#include <cstdio>
using namespace std;
int main()
{
	int h,r;
	scanf("%d %d",&h,&r);
	double v = h*3.1415926*r*r/1000.0;
	double now = 0;
	int res = 0;
	while(now < 20.0)
	{
		now+=v;
		res++;
	}
	printf("%d",res);
}
