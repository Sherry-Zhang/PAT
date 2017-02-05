#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define null -1
struct node
{
	int data;
	int left;
	int right;
};
vector <int> num;
vector <node> t;
void levelorder();
void inorder(int x);
int main()
{
	int n;
	cin >> n;
	int i;
	node temp;
	for(i = 0;i < n;i++)
	{	cin >> temp.left >> temp.right;	
		t.push_back(temp);
	}
	int x;
	for(i = 0;i < n;i++)
	{	cin >> x;
		num.push_back(x);
	}
	sort(num.begin(),num.end());
	inorder(0);
	num.clear();
	levelorder();
	printf("%d",num[0]);
	for(i = 1;i < n;i++)
		printf(" %d",num[i]);
	return 0;
}
int index = 0;
void inorder(int x)
{
	if(x == -1)
		return;
	inorder(t[x].left);
	t[x].data = num[index++];
	inorder(t[x].right);
}
void levelorder()
{
	queue <int> q;
	int p;
	q.push(0);
	while(!q.empty())
	{	p = q.front();
		num.push_back(t[p].data);
		q.pop();
		if(t[p].left != null)
			q.push(t[p].left);
		if(t[p].right != null)
			q.push(t[p].right);
	}
}