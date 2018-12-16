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
	if (tree == NULL) //add root
	{
		tree = (PTREE_NODE)malloc(sizeof(TREE_NODE)); //allocate memory
		if (!tree) //check
			return -1;
		tree->key = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else 
	{
		if (x < tree->key) 
		{
			tree->left = add_node(tree->left, x); //add to the left
		}
		if (x > tree->key) 
		{
			tree->right = add_node(tree->right, x); //add to the right
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
		tree->left = delete_node(tree->left, key); //go left
	else if (key > tree->key)
		tree->right = delete_node(tree->right, key); //go right

	else //remove node
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

		PTREE_NODE temp = max_key_node(tree->left); //insert max element from the left instead of removing node

		tree->key = temp->key;

		tree->right = delete_node(tree->left, temp->key);
	}
	return tree;
}

void destroy_tree(PTREE_NODE tree)
{
	if (tree != NULL)
	{
		destroy_tree(tree->left); //destroy left
		destroy_tree(tree->right); //destroy right
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

/*
 * Helper
 * Arguments: tree - pointer to the tree
 * Returns depth of the tree
 */

int tree_depth(PTREE_NODE tree) {
	int n, m;
	if (tree == NULL) {
		return 0;
	}
	else {
		n = tree_depth(tree->left); //left-tree depth
		m = tree_depth(tree->right); //right depth
		if (m > n) //return max depth
		{
			return m + 1;
		}
		else 
		{
			return n + 1;
		}
	}
}

/*
 * Helper
 * Prints all nodes of the given level
 * Arguments: tree - pointer to the tree, level
 * Returns: none
 */

void tree_lvl(PTREE_NODE tree, int x) {
	if (x == 0) //print root
	{
		printf("%d ", tree->key);
	}
	if (tree->left != NULL) //go left
	{
		tree_lvl(tree->left, x - 1); 
	}
	if (tree->right != NULL) //go right
	{
		tree_lvl(tree->right, x - 1);
	}
}

void wfs(PTREE_NODE tree) {
	int depth = tree_depth(tree); //depth of the tree
	int level;
	for (level = 0; level < depth; level++)
		tree_lvl(tree, level);
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
