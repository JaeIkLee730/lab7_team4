#include <stdio.h>
#include "csapp.h"

static pid_t pid;

int m[17][17] ;

int path[17] ;
int used[17] ;
int length = 0 ;
int min = -1 ;

void _travel(int idx) {
	int i ;

	if (idx == 17) {
		if (min == -1 || min > length) {
			min = length ;
			printf("%d (", length) ;
			for (i = 0 ; i < 16 ; i++) 
				printf("%d ", path[i]) ;
			printf("%d)\n", path[16]) ;
		}
	}
	else {
		for (i = 0 ; i < 17 ; i++) {
			if (used[i] == 0) {
				path[idx] = i ;
				used[i] = 1 ;
				length += m[path[idx-1]][i] ;
				_travel(idx+1) ;
				length -= m[path[idx-1]][i] ;
				used[i] = 0 ;
			}
		}
	}
}

/*void handler(int signum)
{
	int s;
	kill(pid, SIGINT);
	wait(&s);
	printf("ByeByeBye.\n");
}
*/
void travel(int start) {
	path[0] = start ;
	used[start] = 1 ;
	_travel(1) ;
	used[start] = 0 ;
}

void main(int argc, char *argv[]) 
{
	int i, j, t ;
	int stnum = atoi(argv[1]);
	int s;
	pid_t pid;

//	signal(SIGINT, handler);

	FILE * fp = fopen("gr17.tsp", "r") ;

	for (i = 0 ; i < 17 ; i++) {
		for (j = 0 ; j < 17 ; j++) {
			fscanf(fp, "%d", &t) ;
			m[i][j] = t ;
		}
	}
	fclose(fp) ;

	for (i = stnum  ; i < 17 ; i++) 
		travel(i);
	for (i = 0; i < stnum; i++)
		travel(i);
}
