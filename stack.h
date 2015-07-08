/************************************************
  *File: Stack.h
  *
  * Description: Contains the stack data structure
  *		and functions associated with the
  *		stack
  ************************************************/

#include <glib.h>
#include <stdio.h>

/************************************* 
 * The stack data structure:
 * Uses a glib singly linked list
 *
 ************************************/
typedef GQueue * stack;

/***************************************
 * Function: print_iterator
 *
 * Prints item from the stack alongwith 
 * given prefix
 ***************************************/
void print_iterator(gpointer item, gpointer prefix);

/***************************************
 * Function: stack_new
 *
 * Allocates space for the new stack
 ***************************************/
stack stack_new();

/***************************************
 * Function: stack_push
 *
 * Pushes an item to the top of the stack
 ***************************************/
void stack_push(stack s, char * item);

/***************************************
 * Function: stack_pop
 *
 * Pops an item from the top of the stack
 ***************************************/
char * stack_pop(stack s);

/****************************************
 * Function: stack_show_top
 *
 * Prints the top of the stack
 ****************************************/
char * stack_show_top(stack s);

/****************************************
 * Function: stack_print
 *
 * Displays the contents of the stack
 ****************************************/
void stack_print (stack s);
