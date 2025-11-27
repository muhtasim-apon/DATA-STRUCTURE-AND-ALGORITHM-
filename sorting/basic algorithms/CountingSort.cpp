#include <stdio.h>

void counting_sort(int A[], int B[], int k, int n) {
    int C[k + 1]; // Counting array

    // Step 1: Initialize all elements in C to 0
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    // Step 2: Count each element in A
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Step 3: Compute cumulative sum
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    // Step 4: Build the output array B
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;
    int k = 8; // max value in A
    int B[n];

    counting_sort(A, B, k, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;
}
