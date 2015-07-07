
CC=gcc
CFLAGS1=-I/usr/include/glib-2.0/ -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ -I/usr/lib/x86_64-linux-gnu/glib-2.0
CFLAGS2=-lglib-2.0

all: sparse Timer

sparse: testSM.o SparseMatrix.o
	$(CC) $(CFLAGS2) testSM.o SparseMatrix.o
testSM.o: SparseMatrix.h SparseMatrix.c testSM.c
	$(CC) $(CFLAGS1) -c -o testSM.o testSM.c
SparseMatrix.o: SparseMatrix.h SparseMatrix.c
	$(CC) $(CFLAGS1) -c -o SparseMatrix.o SparseMatrix.c

queue: Queue.o QueueTest.o
	$(CC) $(CFLAGS2) Queue.o QueueTest.o
QueueTest.o: Queue.c QueueTest.c
	$(CC) $(CFLAGS1) -c -o QueueTest.o QueueTest.c
Queue.o: Queue.c
	$(CC) $(CFLAGS1) -c -o Queue.o Queue.c

Timer: Timer.o
	$(CC) $(CFLAGS2) Timer.o
Timer.o: Timer.c
	$(CC) $(CFLAGS1) -c -o Timer.o Timer.c

clean:
	rm -f a.out

