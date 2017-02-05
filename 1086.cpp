#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
struct node
{
	int data;
	node *leftchild;
	node *rightchild;
};
typedef node* Tree;
vector <int> preorder;
vector <int> inorder;
vector <int> out;
void postorder(node* root);
Tree create(int preL,int preR,int inL,int inR);
int main()
{
	int n;
	scanf("%d",&n);
	char in[5]={};
	int len,temp;
	stack <int> s;
	for(int i = 0;i < 2 * n;i++)
	{	scanf("%s",in);
		len = strlen(in);
		if(len == 4)
		{	scanf("%d",&temp);
			preorder.push_back(temp);
			s.push(temp);
		}
		else
		{	temp = s.top();
			inorder.push_back(temp);
			s.pop();
		}
	}
	Tree root = create(0,n-1,0,n-1);
	postorder(root);
	printf("%d",out[0]);
	for(int i = 1; i < out.size();i++)
		printf(" %d",out[i]);
	return 0;
}

Tree create(int preL,int preR,int inL,int inR)
{	if(preL > preR)
		return NULL;
	Tree root = new node;
	root->data = preorder[preL];
	int k;
	for(k = inL;k <= inR;k++)
	{	if(inorder[k] == root->data)
			break;
	}
	int left = k - inL;
	root->leftchild = create(preL + 1,preL + left,inL,k - 1);
	root->rightchild = create(preL + left + 1,preR,k + 1,inR);
	return root;
}
void postorder(node* root)
{
	if(root == NULL)
		return;
	postorder(root->leftchild);
	postorder(root->rightchild);
	out.push_back(root->data);
}