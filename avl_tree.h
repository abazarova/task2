/*
*	This file is avl_tree.h
*	AVL tree header
*
*/


#pragma once

typedef struct Node *pnode;

typedef struct Node {
	char *surname;	// unique key - surname
	char *a;	// phone number
	pnode left;	// pointer to the left node
	pnode right;	// pointer to the right node
	int height;
} Node;


/*
*	Adds a new node to the tree
*	Params: x - pointer to the tree, s - surname of a new node, a - phone number of a new node
*	Returns pointer to the updated tree
*	
*/

pnode add_node(pnode x, char s[50], char a[50]);

/*
*	Bfactor is the difference between heights of the left and the right subtrees
*	Params: pnode x - pointer to the node 
*	Returns: height of the right subtree-height of the left subtree
*/

int bfactor(pnode x);

/*
*	Finds height of the subtree
*	Params: p - pointer to the node
*	Returns: height - int
*/

int height(pnode p);

/*
*	Changes height of the subtree (we have to do it after adding new nodes)
*	Params: x - pointer to the subtree
*	Returns: none
*/

void fixheight(pnode p);

/*
*	We need rotateleft and rotateright to keep the tree balanced (height(node->right)-height(node->left) <= 1 is the criterion of AVL tree)	
*	Params: q or p - pointer to the subtree we want to rotate
*	Returns: pnode - pointer to the updated subtree
*/

pnode rotateleft(pnode q);

pnode rotateright(pnode q);

/*
*	We use balance function to make AVL-tree out of our tree after adding new nodes
*	Params: p - pointer to the tree 
*	Returns: pointer to the balanced tree
*/

pnode balance(pnode p);

/*
*	Finds node where node->surname = s
*	Parametres: p - pointer to the tree, s - surname we are looking for
*	Returns: pointer to the found node (NULL if surname is not found)
*/
pnode find_node(pnode p, char s[50]);

/*
*	Prints phone number of the person we are looking for
*	Params: p - pointer to the tree, s - surname we are looking for
*	Returns: none
*/

void find(pnode p, char s[50]);
