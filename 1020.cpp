#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode *leftchild;
	TreeNode *rightchild;
};
typedef struct TreeNode* Tree;
int n;
int postorder[30] = {};
int inorder[30] = {};
Tree create(int postL,int postR,int rightL,int rightR);
void levelorder(Tree &root);
int main()
{

	cin >> n;
	int i;
	for(i = 0;i < n; i++)
		cin >> postorder[i];
	for(i = 0;i < n; i++)
		cin >> inorder[i];
	int postL,postR,inL,inR;
	postL = inL = 0;
	postR = inR = n - 1;
	Tree root = create(postL,postR,inL,inR);
	levelorder(root);
	return 0;
}
Tree create(int postL,int postR,int inL,int inR)
{
	if(postL > postR)
		return NULL;
	Tree root  = new TreeNode;
	root->data = postorder[postR];
	root->leftchild = root->rightchild = NULL;
	int i;
	for(i = inL; i < inR; i++)
	{	if(inorder[i] == postorder[postR])
			break;
	}
	int l = i - inL;
	root->leftchild = create(postL,postL + l - 1,inL,i - 1);
	root->rightchild = create(postL + l,postR - 1,i + 1,inR);
	return root;
}

void levelorder(Tree &root)
{
	queue <Tree> q;
	TreeNode *p;
	q.push(root);
	printf("%d",root->data);
	if(root->leftchild != NULL)
		q.push(root->leftchild);
	if(root->rightchild != NULL)
		q.push(root->rightchild);
	q.pop();
	while(q.empty() == false)
	{	p = q.front();
		printf(" %d",p->data);
		q.pop();
		if(p->leftchild != NULL)
			q.push(p->leftchild);
		if(p->rightchild != NULL)
			q.push(p->rightchild);
	}
}