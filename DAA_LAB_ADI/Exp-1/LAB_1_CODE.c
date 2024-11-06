// 1. IMPLEMENT THE INSERTION INSIDE ITERATIVE AND RECURSIVE BINARY SEARCH TREE AND COMPARE THEIR PERFORMANCE.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// STRUCTURE FOR BST NODE
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// CREATING A NEW NODE
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative BST insertion
struct Node* iterativeInsert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) return newNode;

    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return root; 
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Recursive BST insertion
struct Node* recursiveInsert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = recursiveInsert(root->left, data);
    else if (data > root->data)
        root->right = recursiveInsert(root->right, data);

    return root;
}

// Utility function to print BST in-order (for verification)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Time comparison function for both insertions
void compareInsertionTimes(int arrays[5][10], int sizes[5]) {
    for (int i = 0; i < 5; i++) {
        printf("\n--- Array %d ---\n", i + 1);
        struct Node* root1 = NULL; // For iterative insertions
        struct Node* root2 = NULL; // For recursive insertions

        // Measure time for iterative insertion
        clock_t startIter = clock();
        for (int j = 0; j < sizes[i]; j++) {
            root1 = iterativeInsert(root1, arrays[i][j]);
        }
        clock_t endIter = clock();
        double timeIter = ((double)(endIter - startIter)) / CLOCKS_PER_SEC;

        // Measure time for recursive insertion
        clock_t startRecur = clock();
        for (int j = 0; j < sizes[i]; j++) {
            root2 = recursiveInsert(root2, arrays[i][j]);
        }
        clock_t endRecur = clock();
        double timeRecur = ((double)(endRecur - startRecur)) / CLOCKS_PER_SEC;

        printf("Iterative Insertion Time: %f seconds\n", timeIter);
        printf("Recursive Insertion Time: %f seconds\n", timeRecur);

        // OPTIONAL: PRINT BST (FOR VERIFICATION)
        printf("In-order traversal (Iterative): ");
        inorderTraversal(root1);
        printf("\nIn-order traversal (Recursive): ");
        inorderTraversal(root2);
        printf("\n");
    }
}

int main() {
    // DEFINE FIVE SAMPLE ARRAYS
    int arrays[5][10] = {
        {5, 35, 67, 60, 80, 10, 20},  
        {7, 20, 80, 40, 50, 60, 70, 80, 90}, 
        {25, 35, 58, 10, 22, 35, 70, 40, 80}, 
        {10, 90, 80, 70, 60}, 
        {9, 75, 15, 35, 20, 30, 10}  
    };

    // DEFINE THE SIZE OF EACH ARRAY
    int sizes[5] = {2, 10, 19, 8, 7};

    // COMPARE INSERTION TIMES
    compareInsertionTimes(arrays, sizes);

    return 0;
}