#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int main() {

    setlocale(LC_CTYPE, "rus");

    Node* root = NULL;
    insert(&root, 5, 10);

    printf("Добавление (2, 20): ");
    insert(&root, 2, 20);
    printTreap(root, 0);

    printf("Добавление (8, 15): ");
    insert(&root, 8, 15);
    Node* left, * right;
    printTreap(root, 0);
    printf("Расепление по 5: ");
    split(root, 5, &left, &right);
    printf("\nRight treap: ");
    printTreap(right, 0);
    printf("------------------------------\n");
    printf("\nLeft treap: ");
    printTreap(left, 0);
    printf("------------------------------\n");

    Node* rootL = NULL;
    insert(&rootL, 2, 2);
    insert(&rootL, 1, 1);
    insert(&rootL, 3, 3);
    printf("Левое дерево:");
    printTreap(rootL, 0);

    Node* rootR = NULL;
    insert(&rootR, 6, 10);
    insert(&rootR, 5, 20);
    insert(&rootR, 8, 50);
    printf("Правое дерево:");
    printTreap(rootR, 0);

    Node* newRoot = NULL;
    newRoot = merge(rootL, rootR);
    printf("\nСцепление деревьев: ");
    printTreap(newRoot, 0);

    return 0;
}