#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "csapp.h"

static pid_t pid;

void handler(int signum)
{
        int s,i;
	for(i = 0; i < 17; i++)
	{
	//	sleep(1);
		FILE *f;
		f=fopen("", "a");
		fprintf(f,"%d\n", getpid());
		fclose(f);
        	kill(pid, SIGINT);
       		wait(&s);
	}
        printf("ByeByeBye.\n");
}

void main ()
{
        int s;
	int i = 0;

        signal (SIGINT, handler);

        printf("Let's execute tsp.\n");
	
//	for (i = 0; i < 17; i++)
//	{
       	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "0", NULL);
            }
  //      }

       // for (i = 0; i < 17; i++)
      //  {
        //    if ((pid = fork()) == 0)
          //  {
	//	waitpid(pid, &s, 0);
          //  }
      //  }
            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "1", NULL);
            }
            
	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "2", NULL);
            }

	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "3", NULL);
            }

	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "4", NULL);
            }

	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "5", NULL);
            }

	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "6", NULL);
            }

	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "7", NULL);
            }

 	    if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "8", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "9", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "10", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "11", NULL);
            }
           
	     if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "12", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "13", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "14", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "15", NULL);
            }

            if ((pid = fork()) == 0)
            {
                    execl("./tsp", "tsp", "16", NULL);
            }

            waitpid(pid, &s, 0);
	    waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);
            waitpid(pid, &s, 0);

	exit(0);
}

