/*
 * This file is brackets.h
 * Header for stack implementation
 */

#pragma once

// structures declaration
typedef struct bracket* pbracket;

struct bracket
{
	char value;
	pbracket next;
};

/*
 * Push a bracket to stack
 * Params: top - pointer to the top bracket, new_value - value we want to add
 * Returns: none
 */
void push(pbracket top, int new_value);

/* 
 * Pop a bracket from the stack
 * Params: top - pointer to the top bracket
 * Returns the popped bracket
 */
char pop(pbracket top);
