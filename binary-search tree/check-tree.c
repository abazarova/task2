/*
 * This file is check-tree.c
 * It check is tree AVL or not
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "bst.h"

int check_tree(PTREE_NODE tree)
{
	if (!tree)
		return 1;
	int l = tree_depth(tree->left);
	int r = tree_depth(tree->right);
	if (abs(l - r) <= 1 && check_tree(tree->left) && check_tree(tree->right))
		return 1;
	else return 0;
}