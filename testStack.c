#include <stdio.h>
#include "stack.h"

int main(int argc, char** argv) {
	stack s = stack_new();
	
    stack_push(s,"12343");
	stack_push(s,"2111");
	stack_pop(s);
    stack_push(s, "3343");
    
	printf("Top of stack: %s\n", stack_show_top(s));
	stack_print(s);
	return 0;
}
