#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

#define MAXLEN 50

pmap hashmap_new(void)
{
	pmap map = malloc(sizeof(struct HashMap));

	map->size = MAXLEN;
	map->element_count = 0;

	int i; 
	for (i = 0; i < map->size; i++)
	{
		map->p[i] = malloc(sizeof(pnode));
		map->p[i]->head = malloc(sizeof(pdlist_entry));
		map->p[i]->head = NULL;
		map->p[i]->hash_index = i;
	}
	
	return map;
}

int hash_func(char s[50])
{
	unsigned int i;
	i = strlen(s) % (MAXLEN - 1);

	return i;
}

pmap add(pmap map, char s[50], char a[50])
{
	int i;
	pdlist_entry x;
	
	i = hash_func(s);
	x = find(map, s);
	
	if (NULL == x)
	{
		if (NULL == map->p[i]->head)
		{
			pnode p = malloc(sizeof(pnode));

			p->hash_index = i;
			p->head = malloc(sizeof(pdlist_entry));
			p->head->surname = malloc((strlen(s) + 1) * sizeof(char));
			p->head->number = malloc((strlen(a) + 1) * sizeof(char));
			memcpy(p->head->surname, s, strlen(s) + 1);
			memcpy(p->head->number, a, strlen(a) + 1);
			p->head->next = NULL;
			p->head->prev = NULL;
			map->p[i] = p;
		}
		else
		{
			pdlist_entry t = malloc(sizeof(pdlist_entry));
			t->surname = malloc((strlen(s) + 1) * sizeof(char));
			t->number = malloc((strlen(a) + 1) * sizeof(char));
			memcpy(t->surname, s, strlen(s) + 1);
			memcpy(t->number, a, strlen(a) + 1);
			map->p[i]->head->prev = t;
			t->next = map->p[i]->head;
			t->prev = NULL;
			map->p[i]->head = t;
		}
		map->element_count++;
	}
	else
	{
		printf("%s phone number was changed. Old value: %s \n", x->surname, x->number);
		memcpy(x->number, a, strlen(a) + 1);
	}

	return map;
}

pdlist_entry find(pmap map, char s[50])
{
	int i;
	pdlist_entry x;

	i = hash_func(s);
	x = map->p[i]->head;
	while (NULL != x)
	{
		if (strcmp(s, x->surname) == 0)
			return x;
		x = x->next;
	}
	return NULL;
}

void findnum(pmap map, char s[50])
{
	pdlist_entry x;

	x = malloc(sizeof(pdlist_entry));
	x = find(map, s);
	if (NULL == x)
		printf("Not found");
	else
		printf("%s \n", x->number);
}

int main()
{
	pmap map;
	pdlist_entry x;

	map = malloc(sizeof(pmap));
	map = hashmap_new();
	add(map, "Petrov", "123");
	add(map, "Ivanov", "567");
	findnum(map, "Ivanova");
	free(map);
	return 0;
}

