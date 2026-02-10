// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello

// Output:
// olleh

// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored

// #include <stdio.h>
// #include <string.h>

int main() {
    char str[100];

    scanf("%s", str);

    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}




#include <stdio.h>

int plusOne(int digits[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return n;
        }
        digits[i] = 0;
    }
    for (int i = n; i > 0; i--) {
        digits[i] = digits[i - 1];
    }
    digits[0] = 1;
    return n + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int digits[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &digits[i]);
    }

    n = plusOne(digits, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", digits[i]);
    }

    return 0;
}


