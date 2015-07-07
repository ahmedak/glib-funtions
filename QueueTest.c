
//#include "Queue.c"
#include <stdio.h>
#include <glib.h>

void queueInfo(queue* qqq) {
	printf("The head of the queue is %s\n",queue_show_head(qqq));
	printf("The tail of the queue is %s\n",queue_show_tail(qqq));
	printf("The length of the queue is %d\n",queue_length(qqq));
} // end queueInfo()

int main() {
	queue* qq = NULL;
	char* ch;

	qq =  queue_new();
	printf("Enquing a\n");
	queue_enqueue(qq, "a");
	printf("Enquing b\n");
	queue_enqueue(qq, "b");
	printf("Enquing c\n");
	queue_enqueue(qq, "c");
	printf("Enquing d\n");
	queue_enqueue(qq, "d");
	printf("Enquing e\n");
	queue_enqueue(qq, "e");
	queueInfo(qq);

	printf("Dequeing\n");
	ch = queue_dequeue(qq);
	printf("The dequeued char is %s\n",ch);
	queueInfo(qq);


} // end main()

