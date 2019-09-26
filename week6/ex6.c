//Created by CeeVarouqa
#include <zconf.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char **argv) 
{
    pid_t child1_id, child2_id;

    int pipedata[2]; 

    pipe(pipedata);

    child1_id = fork();

    if (child1_id > 0) 
    {
        child2_id = fork();

        if (child2_id > 0)
        {
            close(pipedata[0]);

            printf("First child:  %d\n", child1_id);
            printf("Second child: %d\n", child2_id);

            write(pipedata[1], &child2_id, sizeof(child2_id));
            close(pipedata[1]);

            waitpid(child2_id, NULL, NULL);

            printf("Child 2 is dead.\n");

        } 
        else if (!child2_id) 
        {
            printf("Child 2 is alive\n");
            while (1);
        }

    }
    else 
    {
        printf("First child is alive\n");
        close(pipedata[1]);
        int second_pid = 0;
        printf("first child is waiting for data.\n");
        read(pipedata[0], &second_pid, sizeof(second_pid));
        kill(second_pid, SIGSTOP);
        printf("Second children PID: %d\n", second_pid);

    }
    return 0;
}