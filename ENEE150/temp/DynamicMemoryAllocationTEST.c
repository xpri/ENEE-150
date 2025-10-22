#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *p, *pTEMP, i, n, d, bool;
    // int pTEMP[10];

    system("cls");
    printf("Enter size of array: ");
    scanf("%d", &n);

    // p = (int *)malloc(n * sizeof(int));
    p = (int *)calloc(n, sizeof(int));
    p = (int *)realloc(p, n + 2 * sizeof(int));

    for (i = 0; i < (n + 2); i++)
    {
        printf("p[%d] = %d\n", i, p[i]);  // Should print 0 for the first n elements, and 0 for the last 2 elements
    }

    // for (int i = 0; i < (n + 2); i++)
    // {
    //     // printf("The number after here should be a %d (n) entries of garbage values: %d\n", n, p[i]);     //when using malloc
    //     // printf("The number after here should be a %d (n) entries of zero: %d\n", n, p[i]);       //when using calloc
    //     printf("The number after here should be a %d (n) entries of zero: %d\n", n, p[i]);       //when using realloc
    // }
    






    // pTEMP = (int *)malloc(n * sizeof(int));

    // for (int i = 0; i <= n; i++)
    // {
    //     pTEMP[i] = i;
    // }

    // for (int i = 0; i <= n; i++)
    // {
    //     p[i] = pTEMP[i];
    // }
    // // printf("%s", p);
    // printf("This is the string of p:\n");
    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%d\n", p[i]);
    // }
    
    free(p);
    return 0;
}