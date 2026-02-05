// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.


#include <stdio.h>

int main()
{
    int a[100], b[100], c[200];
    int p, q;
    int i, j, k;

    printf("Enter number of elements in first log: ");
    scanf("%d", &p);

    printf("Enter elements of first log:\n");
    for(i = 0; i < p; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number of elements in second log:\n ");
    scanf("%d", &q);

    printf("Enter elements of second log:\n");
    for(i = 0; i < q; i++)
    {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    /* merging two sorted arrays */
    while(i < p && j < q)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    /* copy remaining elements */
    while(i < p)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < q)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged log:\n");
    for(i = 0; i < p + q; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
