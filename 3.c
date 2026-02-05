// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main()
{
    int a[100], n, i, k;
    int found = 0;
    int comp = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        comp = comp + 1;

        if(a[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comp);

    return 0;
}
