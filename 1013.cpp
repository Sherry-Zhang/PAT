#include <iostream>
using namespace std;
int G[1000][1000] = {};
int n,e;
int visit[1000] = {};
int repair(int lost);
void DFS(int v,int lost);
int main()
{
	int k;
	cin >> n >> e >> k;
	int v1,v2;
	int i;
	for(i = 0; i < e; i++)
	{	cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	int lostcity;
	for(i = 0; i < k; i++)
	{	cin >> lostcity;
		cout << repair(lostcity) << endl;
	}
	return 0;
}

//本题与列出连通集那道题很类似

int repair(int lost)
{
	int i,count = 0;
	for(i = 1; i <= n; i++)
		visit[i] = 0;
	for(i = 1; i <= n; i++)
	{	if(i == lost)
			continue;
		if(visit[i] == 0)
		{	DFS(i,lost);
			count++;
		}
	}
	return count - 1;
}
void DFS(int v,int lost)
{
	visit[v] = 1;
	for(int i = 1; i <= n; i++)
	{	if(i == lost)
			continue;
		if(G[v][i] == 1 && visit[i] == 0)
			DFS(i,lost);
	}
}