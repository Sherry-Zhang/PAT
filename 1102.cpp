#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define null -1
struct node
{
	int left;
	int right;
};
void in_order(int root);
void level_order(int root);
void Print();
vector <node> t(10);
vector <int> out;
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	char l,r;
	vector <int> visit(n);
	for(i = 0;i < n;i++)
	{	scanf(" %c %c",&r,&l);
		if(l != '-')
		{	t[i].left = l - '0';
			visit[l - '0'] = 1;
		}
		else
			t[i].left = -1;
		if(r != '-')
		{	t[i].right = r - '0';
			visit[r - '0'] = 1;
		}
		else
			t[i].right = -1;
	}
	for(i = 0;i < n;i++)
	{	if(visit[i] == 0)
			break;
	}
	int root = i;
	level_order(root);
	Print();
	out.clear();
	printf("\n");
	in_order(root);
	Print();
	return 0;
}
void level_order(int root)
{
	queue <int> q;
	q.push(root);
	int p;
	while(!q.empty())
	{	p = q.front();
		out.push_back(p);
		q.pop();
		if(t[p].left != null)
			q.push(t[p].left);
		if(t[p].right != null)
			q.push(t[p].right);
	}
}
void in_order(int root)
{
	if(root == null)
		return;
	in_order(t[root].left);
	out.push_back(root);
	in_order(t[root].right);
}
void Print()
{
	printf("%d",out[0]);
	for(int i = 1;i < out.size();i++)
		printf(" %d",out[i]);
}