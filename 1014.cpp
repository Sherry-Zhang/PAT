#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 541
void transfer(vector <int> &wait, int i);
int main()
{
	int N,M,K,Q;
	cin >> N >> M >> K >> Q;
	queue <int>  each_line;	//µÈ´ý¶ÓÁÐ
	vector <queue <int> > _line (N);
	vector <int> time (K + 1);
	vector <int> wait (K + 1);
	int concern;
	int i,j;
	for(i = 1; i <= K; i++)
		cin >> time[i];
	i = 1;
	while(i < N)
	{	for(j = 0; j < N;j++)
		{	if(_line[j].size() < M)
				_line[j].push(i);
		}
	}
	for(i = 0; i < Q ; i++)
	{	cin >> concern;
		transfer(wait,concern);
	}
	return 0;
}
void transfer(vector <int> &wait, int i)
{
}