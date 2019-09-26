//Created by CeeVarouqa
#include <stdio.h>
#include <zconf.h>

int main(int argc, char**argv)
{
    char pipe_1 = "qwertyuiop"; //just random string
    char pipe_2 [99];

    int pipedata [2];
    pipe(pipedata);

    write(pipedata[1], pipe_1, sizeof(pipe_1)+1);
    close(pipe_1[1]);
    read(pipedata[0], pipe_2, sizeof(pipe_2));

    printf("%s from pipe\n", pipe_2);
}