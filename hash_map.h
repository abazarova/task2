/*
*	This file is hash_map.h
*	Hash map implementation
*/


#pragma once


typedef struct HashMap *pmap;
typedef struct HashMapNode *pnode;
typedef struct dlist_entry *pdlist_entry;
typedef struct dlist *pdlist;
 

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
	pdlist_entry head;
} HashMapNode;

typedef struct HashMap
{
	int element_count;
	int size;
	pnode p[50];
} HashMap;

pmap hashmap_new(void);

pmap add(char s[50], char a[50]);

int hash_func(char s[50]);

pdlist_entry find(char s[50]);

void findnum(pmap map, char s[50]);


