//Created by CeeVarouqa
#include<stdio.h>
#include<signal.h>

void handler(int signal_int) 
{
if (signal_int == SIGINT) 
{
    printf("CTRL+C is pressed\n");
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, handler);

    while (1) 
    {
        sleep(1);
        printf(".\n");
    }
}
