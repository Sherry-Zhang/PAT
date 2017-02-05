#include <iostream>
#include <queue>
using namespace std;

int G[10][10] ={};
int visit[10] = {};
int n,e;
void DFS_Travel();
void DFS(int v);
void BFS_Travel();
void BFS(int v);
int main()
{
	cin >> n >> e;
	int v1,v2;
	int i;
	for(i = 0; i < e; i++)
	{	cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	DFS_Travel();
	for(i = 0; i < n; i++)
		visit[i] = 0;
	BFS_Travel();
	return 0;
}

void DFS_Travel()
{
	int i;	
	for(i = 0 ; i < n;i++)
	{	if(visit[i] == 0)
		{	cout << "{ ";
			DFS(i);
			cout << "}\n";
		}
	}
}
void DFS(int v)
{
	cout << v << ' ';
	visit[v] = 1;
	int i;
	for(i = 0;i < n; i++)
	{	if(G[v][i] == 1 && visit[i] == 0)
			DFS(i);
	}
}
//////////////////////////////////////
void BFS_Travel()
{
	int i;

	for(i = 0 ; i < n;i++)
	{	if(visit[i] == 0)
		{	cout << "{ ";
			BFS(i);
			cout << "}\n";
		}
	}
}
void BFS(int v)
{
	queue <int> q;
	q.push(v);
	visit[v] = 1;
	int i;
	while(q.empty() == false)
	{	v = q.front();
		cout << v << ' ';
		q.pop();
		for(i = 0;i < n;i++)
		{	if(G[v][i] == 1 && visit[i] == 0)
			{	q.push(i);
				visit[i] = 1;
			}
		}
	}
}

