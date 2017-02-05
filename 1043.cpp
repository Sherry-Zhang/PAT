#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
typedef node* Tree;
void insert(Tree &t,int x);
void preorder(Tree &t);
void mirror_preorder(Tree &t);
void postorder(Tree &t);
void mirror_postorder(Tree &t);
vector <int> pre;
int main()
{
	int n;
	cin >> n;
	vector <int> in(n);
	int i;
	Tree bst = new node;
	cin >> in[0];
	bst->data = in[0];
	bst->left = bst->right = NULL;
	for(i = 1;i < n;i++)
	{	cin >> in[i];
		insert(bst,in[i]);
	}
	preorder(bst);
	if(pre == in)
	{	printf("YES\n");
		postorder(bst);
	}
	else 
	{	pre.clear();
		mirror_preorder(bst);
		if(pre == in)
		{	printf("YES\n");
			mirror_postorder(bst);
		}
		else
			printf("NO\n");
	}
		
	return 0;
}

void insert(Tree &t,int x)
{
	if(t == NULL)
	{	Tree p = new node;
		p->data = x;
		p->left = p->right = NULL;
		t = p;
		return;
	}
	if(x < t->data)
		insert(t->left,x);
	else
		insert(t->right,x);	
}
void preorder(Tree &t)
{
	if(t == NULL)
		return;
	pre.push_back(t->data);
	preorder(t->left);
	preorder(t->right);
}
void mirror_preorder(Tree &t)
{
	if(t == NULL)
		return;
	pre.push_back(t->data);
	mirror_preorder(t->right);
	mirror_preorder(t->left);
}
bool first = false;
void postorder(Tree &t)
{
	if(t == NULL)
		return;
	postorder(t->left);
	postorder(t->right);
	if(first)
		printf(" %d",t->data);
	else
	{	printf("%d",t->data);
		first = true;
	}
}
void mirror_postorder(Tree &t)
{
	if(t == NULL)
		return;
	mirror_postorder(t->right);
	mirror_postorder(t->left);
	if(first)
		printf(" %d",t->data);
	else
	{	printf("%d",t->data);
		first = true;
	}
}