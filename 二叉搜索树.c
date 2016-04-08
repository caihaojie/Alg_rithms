#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

typedef struct node node;
typedef struct node* bitree;
void inorder_tree_walk(bitree);
bitree tree_search(bitree, int);

bitree buildtree();

void main()
{
	bitree result;
	bitree root = buildtree();
	inorder_tree_walk(root);
	if (result = tree_search(root, 4))
		printf("\n%p\n", result);
	else
		printf("\n未找到\n");
}

bitree buildtree()
{
	int c;
	node *p;
	scanf("%d",&c);
	if (c == 0)
	{
		p = NULL;
	}
	else
	{
		p = (bitree)malloc(sizeof(node));
		p->data = c;
		p->lchild = buildtree();
		p->rchild = buildtree();
	}
	return(p);
}

void inorder_tree_walk(bitree root)
{
	if (root)
	{
		inorder_tree_walk(root->lchild);
		printf("%d", root->data);
		inorder_tree_walk(root->rchild);
	}
}

bitree tree_search(bitree root, int k)
{
	if (!root || k == root->data)
		return root;
	if (root->data > k)
		return tree_search(root->lchild, k);
	else
		return tree_search(root->rchild, k);
}

