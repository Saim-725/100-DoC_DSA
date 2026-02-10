#include <stdio.h>

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    int freq[n];   // frequency array
    int i, j;
    int hasDuplicate = 0;

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        freq[i] = 0;   // initialize frequency
    }

    // Count frequency
    for(i = 0; i < n; i++) {
        if(freq[i] != -1) {
            int count = 1;
            for(j = i + 1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                    freq[j] = -1;   // mark as counted
                }
            }
            freq[i] = count;
            if(count > 1)
                hasDuplicate = 1;
        }
    }

    // Print result
    if(hasDuplicate)
        printf("\nOutput: true\n");
    else
        printf("\nOutput: false\n");

    // Print frequencies
    for(i = 0; i < n; i++) {
        if(freq[i] != -1) {
            printf("%d -> %d\n", nums[i], freq[i]);
        }
    }

    return 0;
}
