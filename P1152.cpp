//P1152 write by cn_ryh
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int nums[n];
	bool all_right[n];
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&nums[i]);
		all_right[i] = false;
	}
	for(int i = 1;i<n;i++)
	{
		if(abs(nums[i] - nums[i-1])<n)
		{
			all_right[i] = true;
		}
	}
	for(int i = 1;i<n;i++)
	{
		if(!all_right[i])
		{
			printf("Not jolly");
			return 0;
		}
	}
	printf("Jolly");
	return 0;
}