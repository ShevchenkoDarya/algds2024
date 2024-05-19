#ifndef LAB_H
#define LAB_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#define BUFFER_SIZE 32
#define STRING_LENGTH 128

typedef struct Node {
    int key, priority;
    struct Node* left, * right, * parent;
} Node;

Node* createNode(int key, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotateRight(Node* node) {
    Node* parent = node->parent;
    Node* child = node->left;

    if (parent) {
        if (parent->left == node) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
    }

    child->parent = parent;
    node->left = child->right;

    if (child->right) {
        child->right->parent = node;
    }

    child->right = node;
    node->parent = child;
}

void rotateLeft(Node* node) {
    Node* parent = node->parent;
    Node* child = node->right;

    if (parent) {
        if (parent->left == node) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
    }

    child->parent = parent;
    node->right = child->left;

    if (child->left) {
        child->left->parent = node;
    }

    child->left = node;
    node->parent = child;
}

void insert(Node** root, int key, int priority) {

    Node* newNode = createNode(key, priority);

    if (!(*root)) {
        *root = newNode;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;

    while (current) {
        parent = current;

        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (key < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }


    while (newNode->parent != NULL && newNode != *root && newNode->priority > newNode->parent->priority) {
        if (newNode->parent->left == newNode) {
            rotateRight(newNode->parent);
        }
        else {
            rotateLeft(newNode->parent);
        }
    }

    if (newNode->parent == NULL) {
        *root = newNode;
    }
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printTreap(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTreap(root->right, space);

    printf("\n");
    printSpaces(space);
    printf("%d,%d\n", root->key, root->priority);

    printTreap(root->left, space);
}

void split(Node* root, int key, Node** left, Node** right) {

    insert(&root, key, INT_MAX); // Insert a dummy node with max priority
    if (root->key == key) {
        *left = root->left;
        *right = root->right;

        if (*right) {
            (*right)->parent = NULL;
            
        }
        if (*left) {
            (*left)->parent = NULL;
            
        }
        free(root);
    }
}

struct Node* merge(struct Node* a, struct Node* b) {

    if (!a) return b;
    if (!b) return a;

    struct Node* res = a;

    while (a && b) {
        if (a->priority < b->priority) {
            if (a->right) {
                if (a->right->priority < b->priority) {
                    struct Node* temp = a->right;
                    a->right = b;
                    b = temp;
                }
                a = a->right;
            }
            else {
                a->right = b;
                break;
            }
        }
        else {
            if (b->left) {
                if (b->left->priority <= a->priority) {
                    struct Node* temp = b->left;
                    b->left = a;
                    a = temp;
                }
                b = b->left;
            }
            else {
                b->left = a;
                break;
            }
        }
    }
    return res;
}

void getStrRepr(Node* root, char* buffer) { 
    /* Represents nodes A(val = 2, priority = 1), B(1, 2), C(3, 3) as string
        A
       / \    -> (2,1,(1,2,-,-),(3,3,-,-))
      B   C
    */

    char str[BUFFER_SIZE];

    if (!root) {
        strcat(buffer, "-");
        return;
    }
    sprintf(str, "(%d,%d,", root->key, root->priority);
    strcat(buffer, str);
    getStrRepr(root->left, buffer);
    strcat(buffer, ",");
    getStrRepr(root->right, buffer);
    strcat(buffer, ")");
}
#endif
