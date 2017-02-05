#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct testee
{
	char ID[14];
	int score;
	int rank;
	int number;
};
bool cmp(const testee &a,const testee &b)
{	if(a.score != b.score)
		return a.score > b.score;
	else if(strcmp(a.ID,b.ID) < 0)
		return true;
	else
		return false;
}
int main()
{
	int n;
	cin >> n;
	vector <vector <testee>> st(n);
	vector <testee> total;
	testee in;
	int i,j,k;
	for(i = 0;i < n;i++)
	{	cin >> k;
		for(j = 0;j < k;j++)
		{	cin >> in.ID >> in.score;
			in.number = i + 1;
			st[i].push_back(in);
		}
		sort(st[i].begin(),st[i].end(),cmp);
		st[i][0].rank = 1;
		total.push_back(st[i][0]);
		for(j = 1;j < k;j++)
		{	if(st[i][j - 1].score == st[i][j].score)
				st[i][j].rank = st[i][j - 1].rank;
			else
				st[i][j].rank = j + 1;
			total.push_back(st[i][j]);
		}
	}
	sort(total.begin(),total.end(),cmp);
	cout << total.size() << endl;
	int rank = 1;
	printf("%s %d %d %d\n",total[0].ID,rank,total[0].number,total[0].rank);
	for(i = 1;i < total.size();i++)
	{	if(total[i].score != total[i - 1].score)
			rank = i + 1;
		printf("%s %d %d %d\n",total[i].ID,rank,total[i].number,total[i].rank);
	}
	return 0;
}
