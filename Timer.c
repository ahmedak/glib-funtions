#include <glib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
	double elapsed;
	char key;
	GTimer * timer = g_timer_new();
	while(1){
		printf("\nTimer started. Press any key to stop timer: ");
		getchar();
		getchar();
		g_timer_stop(timer);
		elapsed = g_timer_elapsed(timer, NULL);
		printf("Time Elapsed: %fs\n", elapsed);
		printf("\nPress 'r' to reset timer, any other key to exit: ");	
		scanf("%c", &key);
		if(key=='r'){
			g_timer_reset(timer);
			getchar();
		}	
		else
			break;
	}
	g_timer_destroy(timer);
	return 0;
}
