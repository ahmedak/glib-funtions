/******************************************
 * File: Queue.h
 * Description: Contains queue data structure 
 *		and related functions
 *
 ******************************************/
#ifndef _queue_h
#define _queue_h

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
queue queue_new();

/********************************************
 * Function: queue_enqueue
 *
 * The element is inserted into queue
 *******************************************/
void queue_enqueue(queue  q, char * s);
	
/********************************************
 * Function: queue_dequeue
 *
 * Dequeues an element and returns it 
 *******************************************/
char * queue_dequeue(queue q);

/********************************************
 * Function: queue_show_head
 *
 * Returns head of queue
 *******************************************/
char * queue_show_head(queue q);

/********************************************
 * Function: queue_show_tail
 *
 * Returns tail of the queue
 *******************************************/
char * queue_show_tail(queue q);

/********************************************
 * Function: queue_length
 *
 * Returns length of queue
 *******************************************/
int queue_length(queue q);

#endif
