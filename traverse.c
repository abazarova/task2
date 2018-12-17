/*
 *	This is traverse.c
 *	This function prints out binary search tree made by M. Seliugin
 *
 */



#define _CRT_SECURE_NO_WARNINGS
#include "bts.h"
#include <stdio.h>
#include <stdlib.h>


void padding(char ch, int n) {
	int i;

	for (i = 0; i < n; i++)
		putchar(ch);
}

void traverse(PTREE_NODE tree, int depth) {

	if (NULL == tree) 
	{
		padding('\t', depth);
		puts(" ");
	}
	else 
	{
		traverse(tree->right, depth + 1);
		padding('\t', depth);
		printf("%d\n", tree->key);
		traverse(tree->left, depth + 1);
	}
}


int main()
{
	PTREE_NODE p;
	p = create_tree();
	p = add_node(p, 5);
	p = add_node(p, 3);
	p = add_node(p, 7);
	p = add_node(p, 8);
	p = add_node(p, 6);
	p = add_node(p, 9);
	traverse(p, 0);

	return 0;
}
