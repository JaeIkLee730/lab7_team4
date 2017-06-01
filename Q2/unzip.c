#include <stdio.h>
#include <string.h>
#include "csapp.h"
#include <unistd.h>

int main( )
{
 //   FILE *pFile = NULL;
    char gzname[63][63];
    int s, i = 0, j = 0;
    pid_t pid;


 //   pFile = fopen( "gzlist.txt", "r" );
    if( stdin != NULL )
    {
        char strTemp[31];
        char *pStr;

        while( !feof(stdin) )
        {
            if((pStr = fgets(strTemp, sizeof(strTemp), stdin)) == NULL) break;
            strcpy(gzname[i++], strTemp);
            gzname[i-1][strlen(gzname[i-1])-4] = '\0';
            printf( "%d %s\n", i, gzname[i-1]);
        }
   //     fclose( pFile );

        for(j=0; j < i; j++)
        {
            if(fork() == 0)
            {
                printf("%d\n", getpid());
                execl("/bin/gzip", "gzip", "-d", gzname[j], NULL);
                exit(0);
            }
        }

        for(j=0; j < i; j++)
        {
            sleep(1);
            pid = wait(&s);
            printf("[%d] terminated.\n", pid);
        }
        printf("Done.\n");
    }

    return 0;
}

