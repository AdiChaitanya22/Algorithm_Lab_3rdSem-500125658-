#include <stdio.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
} Item;

// Function to calculate the value-to-weight ratio
float ratio(Item item) {
    return (float)item.value / item.weight;
}

// Function to sort items based on the ratio in descending order
void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio(items[i]) < ratio(items[j])) {
                // Swap items
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Function to solve the 0/1 Knapsack problem using the greedy approach
int greedyKnapsack(Item items[], int n, int capacity) {
    int totalValue = 0;
    int remainingCapacity = capacity;

    sortItems(items, n);

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        }
    }

    return totalValue;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
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

    int maxValueGreedy = greedyKnapsack(items, n, capacity);
    int maxValueDynamic = dynamicKnapsack(items, n, capacity);

    printf("Maximum value using greedy approach: %d\n", maxValueGreedy);
    printf("Maximum value using dynamic programming approach: %d\n", maxValueDynamic);

    return 0;
}