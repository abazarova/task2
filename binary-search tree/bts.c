/*
 * This file is bst.c
 * Binary Search Tree implementstion
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "bst.h"

PTREE_NODE create_tree(void) 
{
	PTREE_NODE tree = NULL;
	return tree;
}

PTREE_NODE add_node(PTREE_NODE tree, int x)
{
	if (tree == NULL) 
	{
		tree = (PTREE_NODE)malloc(sizeof(TREE_NODE));
		tree->key = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else 
	{
		if (x < tree->key) 
		{
			tree->left = add_node(tree->left, x);
		}
		if (x > tree->key) 
		{
			tree->right = add_node(tree->right, x);
		}
	}
	return tree;
}

/*
 * Helper
 * Finds the node with max key
 * Arguments: tree - pointer to the tree
 * Returns pointer to the found node
 */

PTREE_NODE max_key_node(PTREE_NODE tree)
{
	PTREE_NODE curr = tree;
	while (NULL != curr->right)
		curr = curr->right;

	return curr;
}


PTREE_NODE delete_node(PTREE_NODE tree, int key)
{
	if (NULL == tree)
		return tree;

	if (key < tree->key)
		tree->left = delete_node(tree->left, key);
	else if (key > tree->key)
		tree->right = delete_node(tree->right, key);

	else 
	{
		if (NULL == tree->right)
		{
			PTREE_NODE temp = tree->left;
			free(tree);
			return temp;
		}
		else if (NULL == tree->left) {
			PTREE_NODE temp = tree->right;
			free(tree);
			return temp;
		}

		PTREE_NODE temp = max_key_node(tree->left);

		tree->key = temp->key;

		tree->right = delete_node(tree->left, temp->key);
	}
	return tree;
}

void destroy_tree(PTREE_NODE tree)
{
	if (tree != NULL)
	{
		destroy_tree(tree->left);
		destroy_tree(tree->right);
	}
	tree = NULL;
	free(tree);
}

void dfs(PTREE_NODE tree)
{
	if (tree != NULL)
	{
		dfs(tree->left);
		printf("%d ", tree->key);
		dfs(tree->right);
	}
}

int main() //some tests
{
	PTREE_NODE tree = create_tree();
	tree = add_node(tree, 10);
	tree = add_node(tree, 8);
	tree = add_node(tree, 12);

	dfs(tree);
	return 0;
}
