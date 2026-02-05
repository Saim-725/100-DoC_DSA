// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>

int main()
{
    int a[100], n, i, pos, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    /* shifting elements to the right */
    for(i = n - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }

    a[pos - 1] = x;
    n = n + 1;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

