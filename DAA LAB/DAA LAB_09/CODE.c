#include <stdio.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
} Item;

// Function to implement backtracking approach
void backtrackKnapsack(Item items[], int n, int capacity, int i, int totalValue, int totalWeight) {
    if (i == n) {
        if (totalWeight <= capacity) {
            printf("Backtracking Approach: Total value = %d\n", totalValue);
        }
        return;
    }

    // Include the current item in the knapsack
    if (totalWeight + items[i].weight <= capacity) {
        backtrackKnapsack(items, n, capacity, i + 1, totalValue + items[i].value, totalWeight + items[i].weight);
    }

    // Exclude the current item from the knapsack
    backtrackKnapsack(items, n, capacity, i + 1, totalValue, totalWeight);
}

// Function to implement branch and bound approach
void branchAndBoundKnapsack(Item items[], int n, int capacity, int i, int totalValue, int totalWeight, int upperBound) {
    if (i == n) {
        if (totalWeight <= capacity) {
            printf("Branch and Bound Approach: Total value = %d\n", totalValue);
        }
        return;
    }

    // Calculate the upper bound
    int newUpperBound = upperBound - items[i].value;

    // Include the current item in the knapsack
    if (totalWeight + items[i].weight <= capacity) {
        branchAndBoundKnapsack(items, n, capacity, i + 1, totalValue + items[i].value, totalWeight + items[i].weight, newUpperBound);
    }

    // Exclude the current item from the knapsack
    branchAndBoundKnapsack(items, n, capacity, i + 1, totalValue, totalWeight, upperBound);
}

// Function to implement dynamic programming approach
int dynamicKnapsack(Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (items[i - 1].weight <= j) {
                dp[i][j] = (dp[i - 1][j] > dp[i - 1][j - items[i - 1].weight] + items[i - 1].value) ? dp[i - 1][j] : dp[i - 1][j - items[i - 1].weight] + items[i - 1].value;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    // Define the items
    Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    printf("Backtracking Approach:\n");
    backtrackKnapsack(items, n, capacity, 0, 0, 0);

    printf("\nBranch and Bound Approach:\n");
    branchAndBoundKnapsack(items, n, capacity, 0, 0, 0, 1000);

    printf("\nDynamic Programming Approach:\n");
    int maxValue = dynamicKnapsack(items, n, capacity);
    printf("Total value = %d\n", maxValue);

    return 0;
}