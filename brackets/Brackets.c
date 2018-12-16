/*
 * This is brackets.c
 * Implementation of stack for brackets task
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "Brackets.h"
#define MAX_SIZE 1000

/* push an item to stack*/
void push(pbracket *top, int new_value)
{
	pbracket new_bracket = (pbracket)malloc(sizeof(struct bracket)); //allocate memory

	new_bracket->value = new_value;
	new_bracket->next = *top;

	*top = new_bracket; //move the top
}

/* pop a bracket from the stack */
char pop(pbracket *top)
{
	char res;
	pbracket new_top; //add to free memory
	new_top = *top;
	res = new_top->value;
	*top = new_top->next;
	free(new_top);
	return res;
}

/* Check is it a pair of brackets
 * Params: 2 brackets
 * Return 1 if it is a pair or 0 else
*/
int is_correct(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else
		return 0;
}

/* Check is it a correct expression
 * Params: expression
 * Return 1 if it is correct or 0 else
*/
int are_balanced(char exp[])
{
	int i = 0;

	/* Declare an empty stack */
	pbracket stack = NULL;

	while (exp[i])
	{
		/*If the exp[i] is a starting brackets then push it*/
		if (exp[i] == '{' || exp[i] == '(')
			push(&stack, exp[i]);

		/* If exp[i] is an ending bracket then pop from stack and
		check if the popped bracket is a matching pair*/
		if (exp[i] == '}' || exp[i] == ')')
		{
			/*If we see an ending bracket without a pair then return false*/
			if (NULL == stack)
			{
				return 0;
			}

			if (!is_correct(pop(&stack), exp[i]))
				return 0;
		}

		i++;
	}

	/* If there is something left in expression then there is a starting
	bracket without a closing one */
	if (NULL == stack)
		return 1; //correct
	return 0;  //incorrect
}

int main()
{
	char exp[MAX_SIZE];
	scanf_s("%s", &exp, MAX_SIZE);
	if (are_balanced(exp))
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return 0;
}