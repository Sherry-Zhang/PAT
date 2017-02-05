#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector <int> D(n + 1);
	int i,d;
	int sum = 0;
	D[0] = 0;	//1到1的距离是零
	for(i = 0; i < n;i++)
	{	scanf("%d",&d);
		sum += d;
		D[i+1] = sum;  // 1到 i + 2 的距离
	}
	int m;
	scanf("%d",&m);
	int v1,v2;
	int min_d;
	int dis;
	for(i = 0;i < m;i++)
	{	scanf("%d%d",&v1,&v2);
		if(v1 > v2)
			swap(v1,v2);
		dis = D[v2 - 1] - D[v1 - 1];
		min_d = min(dis,sum - dis);
		printf("%d\n",min_d);
	}
	return 0;
}