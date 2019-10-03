//created by CeeVarouqa
#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    printf("Enter array size:\n");
    int n = 0;
    scanf("%d",&n);

    int* a= malloc(n*sizeof(int));
	int i;

	for(i=0; i<n ; i++)
    {
		a[i]=100;
		printf("%d ", a[i]);
	}

	int n2=0;
    printf("Enter new array size:\n");
	scanf("%d",&n2);

    a = realloc(a, n2);

    for (int i = n; i < n2; i++) 
    {
		a[i] = 0;
	}

    for(i=0; i<n2;i++)
    {
		printf("%d", a[i]);
	}	
	return 0;
}

