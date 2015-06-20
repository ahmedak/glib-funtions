#include <glib.h>

/********************************************
 ** Function: enqueue
 ** Input: q is the queue to which the element s 
 is to be added
 ** Output: void
 ** The element is inserted into queue
 *******************************************/
void enqueue(GQueue * q, char * s){
	g_queue_push_tail(q, s);
}
	
/********************************************
 ** Function: dequeue
 ** Input: queue
 ** Output: the element which is removed
 ** 
 *******************************************/

char * dequeue( GQueue * q) { 
	return	g_queue_pop_head(q);
}


/********************************************
 ** Function: show_head
 ** Input: queue
 ** Output: head of queue
 **
 *******************************************/

char * show_head(GQueue * q) {
	return g_queue_peek_head(q);
}


/********************************************
 ** Function: show_tail
 ** Input: queue
 ** Output: tail of queue
 **
 *******************************************/

char * show_tail(GQueue * q) {
	return g_queue_peek_tail(q);
}


/********************************************
 ** Function: queue_length
 ** Input: queue
 ** Output: length of queue
 **
 *******************************************/

int queue_length(GQueue * q) {
	return g_queue_get_length(q);
}
