

#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n;   // Handle cases where k > n

    // Rotate elements
    for(i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Copy back to original array
    for(i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
