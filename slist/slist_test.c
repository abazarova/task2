#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "slist.h"
#include <stdlib.h>

#define KRED "\x1B[31m" // red
#define KGRN "\x1B[32m" // green
#define KWHT "\x1B[37m" // white
#define KBLK "\x1B[30m" // black

int test1()
{
	pslist list;

	list = slist_new();
	printf("List created! %p\n", list);
	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 3);
	slist_print(list);

	slist_delete(list);
	return 0;
}

int test2()
{
	pslist list = slist_new();

	if (NULL != list->head)
		goto error_path;
	if (0 != list->size)
		goto error_path;

	slist_delete(list);
	return 0;
error_path:
	slist_delete(list);
	return -1;
}

int test3() // This test is made by Anastacia, and your code doesn't pass it :(
{
	pslist list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_remove(list, 1);

	int result = (list->size != 1) ? -1 : 0;
	slist_delete(list);
	return result;
}

int test4() // I'm trying to delete nom-existing element in this test. Description of slist_remove says that the fucntion returns -1
			// if smth goes wrong, but int this test it returns 0. TODO: Fix it
{
	pslist list = slist_new();
	int a; 

	slist_insert(list, 1);
	slist_insert(list, 2);
	a = slist_remove(list, 3);

	return a;

}

int test5()
{
	pslist list = slist_new();
	int x;

	x = slist_insert(list, NULL);
	return x;
}

int main(void)
{
	printf("Hello, " "world!" "\n");
	test1();
	printf("TEST #2 Create list:\t\t%s%s\n", (test2() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT); // or KBLK
	printf("TEST #3 Remove element:\t\t%s%s\n", (test3() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT);
	printf("TEST #4 Remove non-existing element:\t\t%s%s\n", (test4() == -1) ? KGRN"PASSED" : KRED"FAILED", KWHT);
	printf("TEST #5 Add NULL as an element :\t\t%s%s\n", (test5() == -1) ? KGRN"PASSED" : KRED"FAILED", KWHT);

	return 0;
}
