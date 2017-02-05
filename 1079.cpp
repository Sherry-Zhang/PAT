#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	int level;
	vector <int> child;
};
struct leaf
{	int index;
	int acount;
};
void BFS(vector <node> &t);
int main()
{
	int n;
	double p,r;
	cin >> n >> p >> r;
	vector <node> t(n);
	vector <leaf> out;
	int i,j,m,temp;
	for(i = 0;i < n;i++)
	{	cin >> m;
		if(!m)
		{	leaf l;
			cin >> l.acount;
			l.index = i;
			out.push_back(l);
		}
		else
		{	for(j = 0; j < m; j++)
			{	cin >> temp;
				t[i].child.push_back(temp);
			}
		}
	}
	BFS(t);
	double count = 0;
	vector <double> price (n);
	price[0] = p;
	for(i = 1;i < n; i++)
		price[i] = price[i-1] * (1 + r/100);
	for(i = 0;i < out.size();i++)
		count += price[t[out[i].index].level] * out[i].acount;
	printf("%.1f",count);
	return 0;
}
void BFS(vector <node> &t)
{
	queue <int> q;
	t[0].level = 0;
	q.push(0);
	int i,p;
	while(!q.empty())
	{	p = q.front();
		q.pop();
		for(i = 0; i < t[p].child.size();i++)
		{	q.push(t[p].child[i]);
			t[t[p].child[i]].level = t[p].level + 1;
		}
	}
}