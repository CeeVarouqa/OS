//Created by CeeVarouqa
#include <stdio.h>
int main()
{
    int N;
    scanf ("%d", &N);
    int *arr = malloc((N+1)*sizeof(int));
    for (int i = 0; i < N; i++, arr[i] = i);
    for (int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}
