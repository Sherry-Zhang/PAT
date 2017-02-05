#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n;
	double p,r;
	cin >> n >> p >> r;
	int i,j,k,temp;
	vector <vector<int> > child(n);
	vector <int> visit (n);
	for(i = 0;i < n;i++)
	{	cin >> k;
		for(j = 0;j < k;j++)
		{	cin>> temp;
			visit[temp] = 1;
			child[i].push_back(temp);
		}
	}
	for(i = 0;i < n;i++)
		if(visit[i] == 0)
			break;
	int root = i;
	//BFS
	vector <int> level(n);
	queue <int> q;
	q.push(root);
	while(!q.empty())
	{	temp = q.front();
		q.pop();
		if(child[temp].size() == 0)
			break;
		for(i = 0;i < child[temp].size();i++)
		{	q.push(child[temp][i]);
			level[child[temp][i]] = level[temp] + 1;
		}
	}
	int Min = level[temp];
	int count = 1;
	while(!q.empty())
	{	temp = q.front();
		q.pop();
		if(level[temp] == Min && child[temp].size() == 0)
			count++;
	}
	for(i = 0;i < Min;i++)
		p *= (1 + r/100);
	printf("%.4f %d",p,count);
	return 0;
}
