#include <iostream>
#include <vector>
using namespace std;
int N,K,P;
vector <int> out;
vector <int> temp;
vector <int> fac;
int MaxSum = 0;
void DFS(int factor,int s,int sum);
int Power(int x);
void init(void);
int main()
{
	cin >> N >> K >> P;
	init();
	DFS(fac.size() - 1,0,0);
	if(MaxSum == 0)
	{	printf("Impossible\n");
		return 0;
	}
	printf("%d = %d^%d",N,out[0],P);
	for(int i = 1; i < K; i++)
		printf(" + %d^%d",out[i],P);
	return 0;
}

void DFS(int factor,int s,int sum)
{
	if(temp.size() == K && s == N)
	{	if(sum > MaxSum)
		{	MaxSum = sum;
			out = temp;
		}
		return;
	}
	if(s >= N || temp.size() >= K)
		return;
	if(factor > 0)
	{	temp.push_back(factor);
		DFS(factor,s + fac[factor],sum + factor);
		temp.pop_back();
		DFS(factor - 1,s,sum);
	}
}
int Power(int x)
{	int ans = 1;
	for(int i = 0; i < P; i++)
		ans = ans * x;
	return ans;
}
void init()
{
	int i = 0,temp = 0;
	while(temp <= N)
	{	fac.push_back(temp);
		temp = Power(++i);
	}
}
