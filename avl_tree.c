/*
*	This file is avl_tree.c
*	AVL tree implementation
*
*/




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_tree.h"

pnode add_node(pnode x, char s[50], char a[50])
{
	if (NULL == x)
	{
		x = malloc(sizeof(pnode));
		x->surname = malloc(50 * sizeof(char));
		x->a = malloc(50 * sizeof(char));
		memcpy(x->surname, s, strlen(s) + 1);
		memcpy(x->a, a, strlen(a) + 1);
		x->left = NULL;
		x->right = NULL;
	}
	else if (strcmp(s, x->surname) > 0)
		x->right = add_node(x->right, s, a);
	else x->left = add_node(x->left, s, a);

	return balance(x);

}

int height(pnode p)
{
	return p ? p->height : 0;
}

int bfactor(pnode x)
{
	return height(x->right) - height(x->left);
}

void fixheight(pnode p)
{
	int h1 = height(p->left);
	int h2 = height(p->right);

	p->height = (h1 > h2 ? h1 : h2) + 1;
}

pnode rotateright(pnode p)
{
	pnode q;

	q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);

	return q;
}

pnode rotateleft(pnode q)
{
	pnode p;

	p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	
	return p;
}

pnode balance(pnode p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

pnode find_node(pnode p, char s[50])
{
	int check = 0;
	pnode q = p;

	while (check == 0)
	{
		if (strcmp(s, q->surname) == 0)
			return q;
		if (strcmp(s, q->surname) > 0)
		{
			if (NULL != q->right)
				q = q->right;
			else
				check = -1;
		}
		if (strcmp(s, q->surname) < 0)
		{
			if (NULL != q->left)
				q = q->left;
			else
				check = -1;
		}
	}
	if (check == -1)
		return 0;
}

void find(pnode p, char s[50])
{
	pnode q;

	q = find_node(p, s);
	if (NULL == q)
		printf("Not found");
	else
		printf("%s \n", q->a);
}

int main()
{
	pnode t;
	t = NULL;
	char c[50] = "Ivanov";
	char a[50] = "123456";
	t = add_node(t, c, a);
	strcpy(c, "Petrov");
	strcpy(a, "3217569");
	t = add_node(t, c, a);
	find(t, "Sidorov");

	return 0;
}


