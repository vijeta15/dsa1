#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
};

struct AVLNode* createNode(int data) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct AVLNode* insert(struct AVLNode* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void printTreeUtil(struct AVLNode* node, int space) {
    if (node == NULL)
        return;

    int i;
    const int INDENTATION = 4;

    printTreeUtil(node->right, space + INDENTATION);

    for (i = INDENTATION; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);

    printTreeUtil(node->left, space + INDENTATION);
}

void printTree(struct AVLNode* node) {
    printTreeUtil(node, 0);
}

void inorderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    FILE* file = fopen("a.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    struct AVLNode* root = NULL;
    char digit;
    while ((digit = fgetc(file)) != EOF) {
        if (digit >= '0' && digit <= '9') {
            int num = digit - '0';
            root = insert(root, num);
        }
    }

    fclose(file);

    printf("Balanced AVL Tree:\n");
    printTree(root);

    printf("\nInorder traversal of the AVL tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
