#ifndef LAB_H
#define LAB_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>

void Free(int n, int k, int** dp) {
    
    for (int i = 0; i < n + 1; i++) {
        free(dp[i]);
    }
    free(dp);
}

int countNumbers(int n, int k, int** dp) {
    if (k < 0 || k > 9 * n) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x <= 9; x++) {
                if (j - x >= 0) {
                    dp[i][j] += dp[i - 1][j - x];
                }
            }
        }
    }

    return dp[n][k];
}

#endif // !LAB_H
