#include <stdio.h>

// Function to calculate the sum of a subset
void sumOfSubsets(int arr[], int n, int sum, int index, int currentSum) {
    if (index == n) {
        if (currentSum == sum) {
            printf("Subset with sum %d: ", sum);
            for (int i = 0; i < n; i++) {
                if (arr[i] <= sum) {
                    printf("%d ", arr[i]);
                    sum -= arr[i];
                }
            }
            printf("\n");
        }
        return;
    }

    // Include the current element in the subset
    sumOfSubsets(arr, n, sum, index + 1, currentSum + arr[index]);

    // Exclude the current element from the subset
    sumOfSubsets(arr, n, sum, index + 1, currentSum);
}

int main() {
    int arr[] = {2, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;

    printf("Sum of subset problem:\n");
    sumOfSubsets(arr, n, sum, 0, 0);

    return 0;
}