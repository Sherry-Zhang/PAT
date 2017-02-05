#include <iostream>
using namespace std;
int main()
{
	int g1,g2,g3,s1,s2,s3,k1,k2,k3;
	scanf("%d.%d.%d",&g1,&s1,&k1);
	scanf("%d.%d.%d",&g2,&s2,&k2);
	int tk = 0,ts = 0;
	tk = (k1 + k2) / 29;
	k3 = (k1 + k2) % 29;
	ts = (s1 + s2 + tk) / 17;
	s3 = (s1 + s2 + tk) % 17;
	g3 = g1 + g2 + ts;
	printf("%d.%d.%d",g3,s3,k3);
	return 0;
}