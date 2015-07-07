
//#include "Queue.c"
#include <stdio.h>
#include <glib.h>

void queueInfo(GQueue* qqq) {
	printf("The head of the queue is %s\n",show_head(qqq));
	printf("The tail of the queue is %s\n",show_tail(qqq));
	printf("The length of the queue is %d\n",queue_length(qqq));
} // end queueInfo()

int main() {
	GQueue* qq = NULL;
	char* ch;

	qq =  g_queue_new();
	printf("Enquing a\n");
	enqueue(qq, "a");
	printf("Enquing b\n");
	enqueue(qq, "b");
	printf("Enquing c\n");
	enqueue(qq, "c");
	printf("Enquing d\n");
	enqueue(qq, "d");
	printf("Enquing e\n");
	enqueue(qq, "e");
	queueInfo(qq);

	printf("Dequeing\n");
	ch = dequeue(qq);
	printf("The dequeued char is %s\n",ch);
	queueInfo(qq);


} // end main()
