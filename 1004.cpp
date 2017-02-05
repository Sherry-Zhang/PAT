#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	vector <vector <int> > child(n+1);
	int i,j,ID,k;
	int temp;
	for(i = 0;i < m;i++)
	{	cin >> ID >> k;
		for(j = 0;j < k;j++)
		{	cin >> temp;
			child[ID].push_back(temp);
		}
	}
	vector <int> level(n + 1);
	//BFS
	queue <int> q;
	q.push(1);
	int NowLevel = 0;
	vector <int> out;
	int count = 0;
	while(!q.empty())
	{	temp = q.front();
		if(level[temp] == NowLevel)
		{	if(child[temp].size() == 0)
				count++;
		}
		else
		{	printf("%d ",count);
			NowLevel = level[temp];
			count = 0;
			if(child[temp].size() == 0)
				count++;
		}
		q.pop();
		for(i = 0;i < child[temp].size();i++)
		{	q.push(child[temp][i]);
			level[child[temp][i]] = level[temp] + 1;
		}
	}
	printf("%d",count);
	return 0;
}