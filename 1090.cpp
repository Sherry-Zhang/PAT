#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	vector<vector <int> >child(n);
	int i,temp,root;
	for(i = 0; i < n;i++)
	{	scanf("%d",&temp);
		if(temp != -1)
			child[temp].push_back(i);
		else
			root = i;
	}
	vector <int> level(n,0);
	
	//BFS
	queue <int> q;
	q.push(root);
	int k;
	while(!q.empty())
	{	k = q.front();
		q.pop();
		for(i = 0;i < child[k].size();i++)
		{	q.push(child[k][i]);
			level[child[k][i]] = level[k] + 1;
		}
	}
	//out
	int Max = 0,count = 0;
	for(i = 0;i < n;i++)
	{	if(level[i] > Max)
		{	Max = level[i];
			count = 1;
		}
		else if(level[i] == Max)
			count++;
	}
	for(i = 0;i < Max;i++)
		p *= (1 + r/100);
	printf("%.2f %d",p,count);
}
