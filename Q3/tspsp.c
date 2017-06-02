#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "csapp.h"

static pid_t pid;

void handler(int signum)
{
        int s;
        kill(pid, SIGINT);
        wait(&s);
        printf("ByeByeBye.\n");
}

void main ()
{
        int s;
	int i = 0;

        signal (SIGINT, handler);

        printf("Let's execute tsp.\n");
	
	for (i = 0; i < 17; i++)
	{
       	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "i", NULL);
            }
        }

        for (i = 0; i < 17; i++)
        {
            if ((pid = fork()) == 0)
            {
		waitpid(pid, &s, 0);
            }
        }

	exit(0);
}

