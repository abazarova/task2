/*
 *	This file is single_linked_list.h
 *	Doubly linked list
 *
 */

#pragma once
//structures declaration
typedef struct slist_entry *pslist_entry;
typedef struct slist *pslist;

struct slist_entry
{
	int value;
	pslist_entry next;
};

struct slist
{
	int size;
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
*	Returns 0 if everything is OK and the list was deleted;
*/


int slist_delete(pslist list);

/*
 *	Deletes the last element of the list
 *	Parametres: list - pointer to the list, x - saves the deleted element
 *	Returns deleted element
 *
 */

pslist_entry slist_pop(pslist list, pslist_entry *x);

/*
*	Adds new element to the end of the list
*	Params: list - pointer to the list, value - the element we want to add
*	Returns 0 if no errrors
*/

int slist_push(pslist list, int value);
