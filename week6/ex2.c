//Created by CeeVarouqa
#include <stdio.h>
#include <zconf.h>

int main(int argc, char **argv) 
{
    char pipe_1[] = "qwertyuiop";
    char pipe_2[99];
    int pipedata[2];

    pipe(pipedata);

    int process_id = fork();
    if (process_id > 0) 
    {
        close(pipedata[0]);
        write(pipedata[1], pipe_1, (sizeof(pipe_1) + 1));
        close(pipedata[1]);
    } 
    else if (!process_id) 
    {
        close(pipedata[1]);
        read(pipedata[0], pipe_2, sizeof(pipe_2));
        printf("%s From pipe\n", pipe_2);
        close(pipedata[0]);
    }

}