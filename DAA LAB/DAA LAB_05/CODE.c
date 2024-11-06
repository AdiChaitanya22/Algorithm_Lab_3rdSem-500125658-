#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L;

    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int p[] = {30, 35, 15, 5, 10};
    int n = sizeof(p) / sizeof(p[0]);
    int result = matrixChainOrder(p, n);
    printf("Minimum number of scalar multiplications: %d\n", result);
    return 0;
}