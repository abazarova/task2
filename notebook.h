/*
 * This file is struct NOTEbook.h
 * struct NOTEbook implementation on single-list
 *
 */

#pragma once

 //list structures declaration
typedef struct NOTE
{
	char surname[10];
	char number[10];
};
typedef struct slist_entry *pslist_entry;
typedef struct slist *pslist;

struct slist_entry
{
	struct NOTE value;
	pslist_entry next;
};

struct slist
{
	int size; //sugar
	pslist_entry head;
};

/*
 *	Creates empty list
 *	Parametres: none
 *	Returns pointer to the list
 */

pslist slist_new(void);

/*
*	Deletes memory for each element
*	Params: list - pointer to the list we want to delete
*	Returns none
*/


void slist_delete(pslist list);

/*
 *	Deletes the head of the list
 *	Parametres: list - pointer to the list
 *	Returns deleted element
 *
 */

pslist_entry slist_pop(pslist list);

/*
*	Adds new element to the head of the list
*	Params: list - pointer to the list, value - the element we want to add
*	Returns none
*/

int slist_insert(pslist list, struct NOTE value);

/*
*	Remove from the list elements with definite value
*	Params: list - pointer to the list, value - value we want to remove
*	Returns 0
*/

int slist_remove(pslist list, char value[20]);

/*
*	Print list to screen
*	Params: list - pointer to the list
*	Returns none
*/

void slist_print(pslist list);
