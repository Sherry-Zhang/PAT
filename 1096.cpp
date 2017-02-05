#include <iostream>
#include <vector>
using namespace std;

long long N;
vector <long long> temp;
vector <long long> Max_cf;
vector <long long> cf;

void DFS(long long index,long long multi,int level);
void ConsecutiveFactor();

int main()
{
	cin >> N;
	DFS(2,1,0);
	cout << Max_cf.size() << endl;
	cout << Max_cf[0];
	for(int i = 1; i < Max_cf.size();i++)
		printf("*%lld",Max_cf[i]);
	return 0;
}

void DFS(long long index,long long multi,int level)
{
	if(multi == N && temp.size() > Max_cf.size())
	{	ConsecutiveFactor();
		return;
	}
	if(multi >= N || level > 11)
		return;
	if(multi * index <= N)
	{	temp.push_back(index);
		DFS(index,multi*index,level+1);
		temp.pop_back();
		DFS(index+1,multi,level);
	}
}
void ConsecutiveFactor()
{	cf.clear();
	cf.push_back(temp[0]);
	for(int i = 1;i < temp.size();i++)
	{	if(temp[i] == temp[i-1] + 1)
			cf.push_back(temp[i]);
		else
		{	if(cf.size() > Max_cf.size())
				Max_cf = cf;
			cf.clear();
			cf.push_back(temp[i]);
		}
	}
	if(cf.size() > Max_cf.size())
		Max_cf = cf;
}