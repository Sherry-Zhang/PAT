#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void inorder(int p);
vector <int> in;
vector <int> t;
int main()
{
	int n;
	cin >> n;
	int i,temp;
	for(i = 0; i < n; i++)
	{	cin >> temp;
		in.push_back(temp);
	}
	sort(in.begin(),in.end());
	t = in;
	inorder(0);
	printf("%d",in[0]);
	for(i = 1;i < n;i++)
		printf(" %d",in[i]);
	return 0;
}
int index = 0;
void inorder(int p)
{
	if(p >= t.size())
		return;
	inorder(p * 2 + 1);
	in[p] = t[index++];
	inorder(p * 2 + 2);
}
