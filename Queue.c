#include "Queue.h"

/* Allocates space for a new queue */
queue queue_new(){
	return g_queue_new();
}

/* The element is inserted into queue */
void queue_enqueue(queue  q, char * s){
	g_queue_push_tail(q, s);
}
	
/* Dequeues an element and returns it */
char * queue_dequeue(queue q) { 
	return	g_queue_pop_head(q);
}

/* Returns head of queue */
char * queue_show_head(queue q) {
	return g_queue_peek_head(q);
}

/* Returns tail of the queue */
char * queue_show_tail(queue q) {
	return g_queue_peek_tail(q);
}

/* Returns length of queue */
int queue_length(queue q) {
	return g_queue_get_length(q);
}
