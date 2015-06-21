/************************************************
  *File: Stack.c
  *
  *Description: Contains the stack data structure
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
 * Input: item from stack and prefix
 * Output: void
 * 
 * Prints item from the stack alongwith 
 * given prefix
 ***************************************/
void print_iterator(gpointer item, gpointer prefix) {
	printf("%s %s\n", (char*)prefix, (char *)item);
}

/***************************************
 * Function: stack_new
 * Input: none
 * Output: stack
 * 
 * Allocates space for the new stack
 ***************************************/
stack stack_new(){
	return g_queue_new();
}

/***************************************
 * Function: stack_push
 * Input: Stack, and item to be pushed
 * Output: void
 * 
 * Pushes an item to the top of the stack
 ***************************************/
void stack_push(stack s, char * item){
	g_queue_push_head(s, item);
}

/***************************************
 * Function: stack_pop
 * Input: Stack
 * Output: the item which is popped
 *
 * Pops an item from the top of the stack
 ***************************************/
char * stack_pop(stack s){
	return g_queue_pop_head(s);
}

/****************************************
 * Function: stack_show_top
 * Input: Stack
 * Output: The item at the top of the stack
 *
 * Prints the top of the stack
 ****************************************/
char * stack_show_top(stack s){
	return g_queue_peek_head(s);
}

/****************************************
 * Function: stack_print
 * Input: Stack
 * Output: void
 *
 * Displays the contents of the stack
 ****************************************/
void stack_print (stack s){
	printf("-->");
	g_queue_foreach(s, print_iterator, "\t");	
}
