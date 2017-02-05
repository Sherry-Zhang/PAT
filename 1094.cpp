#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	vector <vector <int> > child (n + 1);//´Ó1¿ªÊ¼´æ´¢
	int i,j;
	int ID,temp,k;
	for(i = 0;i < m;i++)
	{	cin >> ID >> k;
		for(j = 0; j < k;j++)
		{	cin >> temp;
			child[ID].push_back(temp);
		}
	}
	vector <int> level(n + 1);
	vector <int> count(n + 1);
	queue <int> q;
	level[1] = 1;
	q.push(1);
	while(!q.empty())
	{	temp = q.front();
		q.pop();
		for(i = 0;i < child[temp].size();i++)
		{	q.push(child[temp][i]);
			level[child[temp][i]] = level[temp] + 1;
		}
	}
	int M = 1;
	for(i = 1;i <= n;i++)
	{	
		count[level[i]]++;
		if(count[level[i]] > count[M])
			M = level[i];
	}
	cout << count[M] << ' ' << M;
	return 0;
}