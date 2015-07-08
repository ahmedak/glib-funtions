/******************************************
 * File: Queue.c
 * Description: Contains queue data structure 
 *		and related functions
 *
 ******************************************/

#include <glib.h>

/******************************************* 
 * The Queue data structure
 * Uses inbuilt Gqueue data structure of glib
 ********************************************/
typedef GQueue * queue;

/********************************************
 * Function: queue_new
 *
 * Allocates space for a new queue
 *******************************************/
queue queue_new(){
	return g_queue_new();
}

/********************************************
 * Function: queue_enqueue
 *
 * The element is inserted into queue
 *******************************************/
void queue_enqueue(queue  q, char * s){
	g_queue_push_tail(q, s);
}
	
/********************************************
 * Function: queue_dequeue
 *
 * Dequeues an element and returns it 
 *******************************************/
char * queue_dequeue(queue q) { 
	return	g_queue_pop_head(q);
}


/********************************************
 * Function: queue_show_head
 *
 * Returns head of queue
 *******************************************/
char * queue_show_head(queue q) {
	return g_queue_peek_head(q);
}


/********************************************
 * Function: queue_show_tail
 *
 * Returns tail of the queue
 *******************************************/
char * queue_show_tail(queue q) {
	return g_queue_peek_tail(q);
}


/********************************************
 * Function: queue_length
 *
 * Returns length of queue
 *******************************************/
int queue_length(queue q) {
	return g_queue_get_length(q);
}
