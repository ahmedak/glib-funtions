#include <glib.h>
#include <stdio.h>
#include "stack.h"

void print_iterator(gpointer item, gpointer prefix) {
	printf("%s %s\n", (char*)prefix, (char *)item);
}

stack stack_new(){
	return g_queue_new();
}

void stack_push(stack s, char * item){
	g_queue_push_head(s, item);
}

char * stack_pop(stack s){
	return g_queue_pop_head(s);
}

char * stack_show_top(stack s){
	return g_queue_peek_head(s);
}

void stack_print (stack s){
	printf("-->");
	g_queue_foreach(s, print_iterator, "\t");	
}
