/*
*	This file is hash_map.h
*	Hash map implementation
*/


#pragma once


typedef struct HashMap *pmap;
typedef struct HashMapNode *pnode;
typedef struct dlist_entry *pdlist_entry;
typedef struct dlist *pdlist;
 
// I use dlist structures to avoid collisions (separate chaining method)

struct dlist_entry
{
	char *surname;
	char *number;
	pdlist_entry next;
	pdlist_entry prev;
};


typedef struct HashMapNode
{
	unsigned int hash_index;
	pdlist_entry head; // every node in my hashmap is a doubly-linked list
} HashMapNode;

typedef struct HashMap
{
	int element_count;
	int size;
	pnode p[50];
} HashMap;

/*
 *	Creates new hashmap
 *	Params: none
 *	Returns pointer to the hashmap
 */

pmap hashmap_new(void);

/*
 *	Adds new element to the hashmap
 *	Params: s[50] - surname, a[50] - phone number
 *	Returns pointer to the updated hashmap
 */

pmap add(char s[50], char a[50]);

/*
 *	Transforms surname to hash index
 *	Params: s[50] - surname
 *	Returns: int - hash index (strlen(surname) mod 49)
 */

int hash_func(char s[50]);

/*
 *	Finds an element where surname = s
 *	Params: s[50] - surname, map - pointer to the hashmap
 *	Returns pointer to the element of the hashmap 
 */

pdlist_entry find(pmap map, char s[50]);

/*
 *	Prints phone number of the person with surname = s[50]
 *	Params: map - pointer to the hashmap, s[50] - surname
 *	Returns none
 */

void findnum(pmap map, char s[50]);


