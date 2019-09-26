//Created by CeeVarouqa
#include <stdio.h>
#include <signal.h>

void handler(int signal_int)
{
    if (signal_int == SIGUSR1) 
    {
        printf("SIGUSR1\n");
    } 
    else if (signal_int == SIGSTOP) 
    {
        printf("SIGSTOP\n");
    } 
    else if (signal_int == SIGKILL) 
    {
        printf("SIGKILL\n");
    }
}

void check_result(int result, int code) 
{
    if (result)
        printf("signal is not with code %d\n", code);
    else
        printf("signal is with code %d\n", code);
}

int main(int argc, char **argv) 
{
    int result;
    result = signal(SIGUSR1, handler);
    check_result(result, SIGUSR1);

    result = signal(SIGKILL, handler);
    check_result(result, SIGKILL);

    result = signal(SIGSTOP, handler);
    check_result(result, SIGSTOP);

    while (1) 
    {
        sleep(1);
        printf(".\n");
    }
}