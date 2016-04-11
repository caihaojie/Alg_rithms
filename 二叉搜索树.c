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
	;
}

/*************************************************
Function: buildtree()
Description: 构建二叉树
Calls: malloc()
Called By: main()
Input: NULL
Output: NULL
Return: 构建完成的二叉树根结点
Others: 按照前序遍历的顺序输入data值，输入0代表空结点
*************************************************/
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

/*************************************************
Function: inorder_tree_walk(bitree root)
Description: 遍历输出二叉树中的data
Calls: NULL
Called By: main()
Input:  bitree root->二叉树根节点
Output: 二叉树中的data
Return: NULL
Others: 递归实现
*************************************************/
void inorder_tree_walk(bitree root)
{
	if (root)
	{
		inorder_tree_walk(root->lchild);
		printf("%d", root->data);
		inorder_tree_walk(root->rchild);
	}
}

/*************************************************
Function: interative_tree_search(bitree root, int k)
Description: 返回二叉树中data等于k的结点
Calls: NULL
Called By: main()
Input:  bitree root->二叉树根节点
		int k->要查找的data
Output: NULL
Return: data等于k的结点
Others: 递归实现
*************************************************/
bitree tree_search(bitree root, int k)
{
	if (!root || k == root->data)
		return root;
	if (root->data > k)
		return tree_search(root->lchild, k);
	else
		return tree_search(root->rchild, k);
}

/*************************************************
Function: interative_tree_search(bitree root, int k)
Description: 返回二叉树中data等于k的结点
Calls: NULL
Called By: main()
Input:  bitree root->二叉树根节点
		int k->要查找的data
Output: NULL
Return: data等于k的结点
Others: 非递归实现
*************************************************/
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

/*************************************************
Function: tree_minimum(bitree root)
Description: 返回二叉树中data最小的结点
Calls: NULL
Called By: main()
Input:  bitree root->二叉树根节点
Output: NULL
Return: data最小的结点
Others: NULL
*************************************************/
bitree tree_minimum(bitree root)
{
	while (root->lchild)
		root = root->lchild;
	return root;
}

/*************************************************
Function: tree_maximum(bitree root)
Description: 返回二叉树中data最大的结点
Calls: NULL
Called By: main()
Input:  bitree root->二叉树根节点
Output: NULL
Return: data最大的结点
Others: NULL
*************************************************/
bitree tree_maximum(bitree root)
{
	while (root->rchild)
		root = root->rchild;
	return root;
}

/*************************************************
Function: tree_insert(bitree* root_address, bitree k)
Description: 向二叉树中插入新结点k
Calls: NULL
Called By: main()
Input:  bitree root->二叉树根节点地址
		bitree k->要插入的结点
Output: NULL
Return: NULL
Others: NULL
*************************************************/
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

/*************************************************
Function: parent_search(bitree root, bitree son)
Description: 返回二叉树中结点son的父结点
Calls: parent_search()
Called By: main()
Input:  bitree root->二叉树根节点
		bitree son->子结点
Output: NULL
Return: son的父结点
Others: 递归实现
*************************************************/
bitree parent_search(bitree root, bitree son)
{
	if (!root || root->lchild == son || root->rchild == son)
		return root;
	return parent_search(root->lchild, son);
	return parent_search(root->rchild, son);
}

/*************************************************
Function: transplant(bitree* root_address, bitree old, bitree new)
Description: 把二叉树中的old结点换成new
Calls: parent_search()
Called By: main()
Input:  bitree* root_address->二叉树根节点地址
		bitree old->要被替换的结点
		bitree new->要替换的新结点
Output: NULL
Return: NULL
Others: NULL
*************************************************/
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