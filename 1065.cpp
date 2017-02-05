#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	long long a,b,c;
	long long res;
	for(i = 0; i < n; i++)
	{	scanf("%lld %lld %lld",&a,&b,&c);
		res = a + b;
		if((a < 0 && b < 0) && res >= 0)
			printf("Case #%d: false\n",i + 1);
		else if((a > 0 && b > 0) && res <= 0)
			printf("Case #%d: true\n",i + 1);
		else if(res > c)
			printf("Case #%d: true\n",i + 1);
		else 
			printf("Case #%d: false\n",i + 1);
	}
	return 0;
}