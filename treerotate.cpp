#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct Node {
    KeyType Key;
    int Height;
    struct Node* Left;
    struct Node* Right;
} Node;

typedef Node* Tree;

// Hàm tìm giá tr? l?n nh?t
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Hàm l?y chi?u cao c?a node
int getHeight(Tree node) {
    return (node == NULL) ? 0 : node->Height;
}

// Hàm tính h? s? cân b?ng c?a m?t node
int getBalance(Tree node) {
    if (node == NULL) return 0;
    return getHeight(node->Left) - getHeight(node->Right);
}

// Xoay ph?i
Tree rightRotate(Tree T) {
    if (T == NULL || T->Left == NULL)
        return T;  // Không xoay n?u không d? di?u ki?n

    Tree tmp = T->Left;
    T->Left = tmp->Right;
    tmp->Right = T;

    // C?p nh?t chi?u cao
    T->Height = max(getHeight(T->Left), getHeight(T->Right)) + 1;
    tmp->Height = max(getHeight(tmp->Left), getHeight(tmp->Right)) + 1;

    return tmp;
}

// Xoay trái
Tree leftRotate(Tree x) {
    if (x == NULL || x->Right == NULL)
        return x;

    Tree y = x->Right;
    Tree T2 = y->Left;

    // Xoay trái
    y->Left = x;
    x->Right = T2;

    // C?p nh?t chi?u cao
    x->Height = max(getHeight(x->Left), getHeight(x->Right)) + 1;
    y->Height = max(getHeight(y->Left), getHeight(y->Right)) + 1;

    return y;
}

// Xoay trái r?i ph?i (Left-Right Rotation)
Tree leftrightRotate(Tree T) {
    if (T == NULL) return T;
    T->Left = leftRotate(T->Left);
    return rightRotate(T);
}

// Xoay ph?i r?i trái (Right-Left Rotation)
Tree rightleftRotate(Tree T) {
    if (T == NULL) return T;
    T->Right = rightRotate(T->Right);
    return leftRotate(T);
}

