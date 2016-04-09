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
bitree interative_tree_search(bitree, int);
bitree tree_minimum(bitree);
bitree tree_maximum(bitree);
void tree_insert(bitree*, bitree);
bitree parent_search(bitree, bitree);
void transplant(bitree*, bitree, bitree);

void main()
{
	bitree result;
	bitree root = buildtree();
	inorder_tree_walk(root);
	if (result = tree_search(root, 4))
		printf("\n%p\n", result);
	else
		printf("\n未找到\n");

	if (result = interative_tree_search(root, 4))
		printf("\n%p\n", result);
	else
		printf("\n未找到\n");

	inorder_tree_walk(root);
		
	bitree k;
	k = (bitree)malloc(sizeof(node));
	k->data = 1;
	k->lchild = NULL;
	k->rchild = NULL;
	//tree_insert(&root, k);
	//inorder_tree_walk(root);


	transplant(&root, root->lchild->lchild, k);

	inorder_tree_walk(root);
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

bitree interative_tree_search(bitree root, int k)
{
	while (root && root->data != k)
	{
		if (root->data > k)
			root = root->lchild;
		else
			root = root->rchild;
	}

	return root;
}

bitree tree_minimum(bitree root)
{
	while (root->lchild)
		root = root->lchild;
	return root;
}

bitree tree_maximum(bitree root)
{
	while (root->rchild)
		root = root->rchild;
	return root;
}

void tree_insert(bitree* root_address, bitree k)
{
	if (*root_address)
	{
		bitree y = *root_address;
		bitree temp = *root_address;
		while (temp)
		{
			y = temp;
			if (k->data > (temp)->data)
				temp = (temp)->rchild;
			else
				temp = (temp)->lchild;
		}

		if (k->data > y->data)
			y->rchild = k;
		else
			y->lchild = k;
	}
	else
	{
		*root_address = (bitree)malloc(sizeof(node));
		(*root_address)->data = k->data;
		(*root_address)->lchild = (*root_address)->rchild = NULL;
	}
}

bitree parent_search(bitree root, bitree son)
{
	if (!root || root->lchild == son || root->rchild == son)
		return root;
	return parent_search(root->lchild, son);
	return parent_search(root->rchild, son);
}

void transplant(bitree* root_address, bitree old, bitree new)
{
	bitree parent = parent_search(*root_address, old);
	if (!parent)
		*root_address = parent;
	else if (old == parent->lchild)
		parent->lchild = new;
	else
		parent->rchild = new;
}
