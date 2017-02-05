#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct root
{	int data;
	int level;
};
vector <vector<int> > adj(10001);
int n;
vector <root> deep;
vector <int> visit(10001);
void bfs(int v);
bool cmp(const root &a,const root &b)
{
	if(a.level != b.level)
		return a.level > b.level;
	else
		return a.data < b.data;
}
int main()
{
	cin >> n;
	int i,v1,v2;
	for(i = 0;i < n - 1;i++)
	{	cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int count = 0;
	for(i = 1;i <= n;i++)
	{	if(visit[i] == 0)
		{	bfs(i);
			count++;
		}
	}
	if(count != 1)
	{	printf("Error: %d components",count);
		return 0;
	}
	for(i = 2;i <= n;i++)
	{	fill(visit.begin(),visit.end(),0);
		bfs(i);
	}
	sort(deep.begin(),deep.end(),cmp);
	int deepest = deep[0].level;
	for(i = 0;i < deep.size();i++)
	{	if(deep[i].level == deepest)
			cout << deep[i].data << endl;
		else
			break;
	}
	return 0;
}
void bfs(int v)
{
	queue <int> q;
	q.push(v);
	visit[v] = 1;
	int p;
	while(!q.empty())
	{	p = q.front();
		q.pop();
		for(int i = 0;i < adj[p].size();i++)
		{	if(visit[adj[p][i]] == 0)
			{	q.push(adj[p][i]);
				visit[adj[p][i]] = visit[p] + 1;
			}
		}
	}
	root r;
	r.data = v;
	r.level = visit[p];
	deep.push_back(r);
}