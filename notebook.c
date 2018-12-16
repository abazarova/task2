/*
 * This file is notebook.c
 * Notebook realisation on single-list
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "notebook.h"

int insert(pslist list, struct NOTE note)
{
	slist_remove(list, note.surname);
	slist_insert(list, note);
}

int main()
{
	struct NOTE note;
	pslist list;
	note.surname[10] = "Petrov";
	note.number[10] = "265265";
	list = slist_new;
	insert(list, note);
	return 0;
}