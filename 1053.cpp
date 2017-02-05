#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
	int weight;
	vector <int>child;
};
int s;
vector <node> t;
vector <int> path;
void Print();
void DFS(int r,int sum);
bool cmp(const int &a,const int &b)
{
	return t[a].weight > t[b].weight;
}
int main()
{
	int n,m;
	cin >> n >> m >> s;
	node r;
	int i,j,ID,k,temp;
	for(i = 0;i < n;i++)
	{	cin >> r.weight;
		t.push_back(r);
	}
	for(i = 0; i < m; i++)
	{	cin >> ID >> k;
		for(j = 0;j < k;j++)
		{	cin >> temp;
			t[ID].child.push_back(temp);
		}
		sort(t[ID].child.begin(),t[ID].child.end(),cmp);
	}
	path.push_back(t[0].weight);
	DFS(0,t[0].weight);
	return 0;
}

void DFS(int r,int sum)
{	if(t[r].child.size() == 0 && sum == s)
	{	Print();
		return;
	}
	if(sum >= s)
		return;
	for(int i = 0;i < t[r].child.size();i++)
	{	path.push_back(t[t[r].child[i]].weight);
		DFS(t[r].child[i],sum + t[t[r].child[i]].weight);
		path.pop_back();
	}
}
void Print()
{
	printf("%d",path[0]);
	for(int i = 1; i < path.size();i++)
		printf(" %d",path[i]);
	printf("\n");
}