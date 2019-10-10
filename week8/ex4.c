//Created by CeeVarouqa
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
int main()
{
    for (int i = 0; i < 10; i++)
    {
        struct rusage usage;
        memset(malloc((1<<21)*5), 0, (1<<21)*5);
        getrusage(RUSAGE_SELF, &usage);
        printf("maximum resident set size: %ld\n", usage.ru_maxrss);
        sleep(1);
    }  
}
