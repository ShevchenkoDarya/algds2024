#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Header.h"
#include <malloc.h>

int main() {
    int n, k;
    setlocale(LC_CTYPE, "rus");
    printf("������� ���������� ���� n � ����� ���� k: ");
    scanf("%d %d", &n, &k);

    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i < n + 1; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));
    }

    int result = countNumbers(n, k, dp);
    printf("���������� %d-������� ����� � ������ ���� %d: %d\n", n, k, result);
    Free(n, k, dp);

    return 0;
}
