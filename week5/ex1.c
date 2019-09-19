//Created by CeeVarouqa

#include <stdio.h>
#include <pthread.h>
int N = 10;
void *function(void *a)
{
    printf("Thread no: %d \n", a);
    pthread_exit(NULL);
}
void pair()
{
    pthread_t thread[1000];
    for (int i = 0; i < N; i++)
    {
        pthread_create(&threads[i], NULL, func, (void *)i);    
    }
    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
}

void seq() {
	pthread_t threads[1000];
	for (int i = 0; i < N; i++) 
    {
		pthread_create(&threads[i], NULL, func, (void *)i);
		pthread_join(threads[i], NULL);
    }
}

int main()
{
    pthread_t threads[1000];
    printf("Parallel:\n");
	parallel();
	printf("\n\n\n Sequence:\n");
	sequence();
	return 0;
}



