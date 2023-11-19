#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void inputBinaryTree(struct Node* givenNode) {
    int leftValue, rightValue;

    printf("Enter left child value (or -1 to skip): ");
    scanf("%d", &leftValue);

    if (leftValue != -1) {
        givenNode->left = newNode(leftValue);
        inputBinaryTree(givenNode->left);
    }

    printf("Enter right child value (or -1 to skip): ");
    scanf("%d", &rightValue);

    if (rightValue != -1) {
        givenNode->right = newNode(rightValue);
        inputBinaryTree(givenNode->right);
    }
}

void displayBinaryTree(struct Node* node, int tabs) {
    if (node == NULL) {
        return;
    }

    displayBinaryTree(node->right, tabs + 1);

    for (int i = 0; i < tabs; i++) {
        printf("    ");
    }
    printf("%d\n", node->data);

    displayBinaryTree(node->left, tabs + 1);
}

void calculateHeightOfBinaryTree(struct Node* node, int currentheight, int* resultHeight) {

    if (node == NULL) {
        if (currentheight > *resultHeight) {
            *resultHeight = currentheight;
        }
        return;
    }
    
    calculateHeightOfBinaryTree(node->right, currentheight + 1, resultHeight);

    calculateHeightOfBinaryTree(node->left, currentheight + 1, resultHeight);
}

void countLeafNodes(struct Node* node, int* resultLeafNodes) {

    if (node == NULL) {
        return;
    }

    if (node->left == NULL && node->right == NULL) {
        *resultLeafNodes = *resultLeafNodes + 1;
        return;
    }
    
    countLeafNodes(node->right, resultLeafNodes);

    countLeafNodes(node->left, resultLeafNodes);
}

void displayInorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }

    displayInorderTraversal(node->left);
 
    printf("%d ", node->data);
 
    displayInorderTraversal(node->right);
}

void countTotalNodes(struct Node* node, int* nrOfNodes) {
    if (node == NULL) {
        return;
    }
    
    *nrOfNodes = *nrOfNodes + 1;
    
    countTotalNodes(node->right, nrOfNodes);
    
    countTotalNodes(node->left, nrOfNodes);
    
}

void fillArrWithInorderTraversal(struct Node* node, int* arr, int* index) {
    if (node == NULL) {
        return;
    }

    fillArrWithInorderTraversal(node->left, arr, index);
 
    arr[*index] = node->data;
    (*index)++;
 
    fillArrWithInorderTraversal(node->right, arr, index);
}

// check if the array is sorted in ascending order
void checkIfBinaryTreeIsBST(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) {
                printf("\nNot a Binary Search Tree (BST)");
                return;
            }
        }
    }
    
    printf("\nYes, it is a Binary Search Tree (BST)");
}

struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* node, int val) {
    if (node == NULL) {
        return node;
    }

    // the value to be deleted is in the left subtree
    if (val < node->data) {
        node->left = deleteNode(node->left, val);
    }
    // the value to be deleted is in the right subtree
    else if (val > node->data) {
        node->right = deleteNode(node->right, val);
    }
    // the value is equal to this node's value
    else {
        // has only one child or no child
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }

        // has two children, get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMinValueNode(node->right);

        // copy the inorder successor's value to this node
        node->data = temp->data;

        // delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

int isBalanced(struct Node* node) {
    if (node == NULL) {
        return 1;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // Check the difference of left and right subtrees
    return (abs(leftHeight - rightHeight) <= 1) && isBalanced(node->left) && isBalanced(node->right);
}

int main() {
    int num;
    printf("Input Binary Tree with integers\nRoot: ");
    scanf("%d", &num);
    struct Node* root = newNode(num);
    inputBinaryTree(root);

    // mandatory task
    printf("\nBinary Tree:\n");
    displayBinaryTree(root, 0);

    // easy task 1
    int resultHeight = 0;
    calculateHeightOfBinaryTree(root, 0, &resultHeight);
    printf("\nHeight: %d", resultHeight);
    
    // easy task 2
    int resultLeafNodes = 0;
    countLeafNodes(root, &resultLeafNodes);
    printf("\nLeaf Nodes: %d", resultLeafNodes);
    
    // easy task 3
    printf("\nIn-order traversal: ");
    displayInorderTraversal(root);
    
    // easy task 4
    int nrOfNodes = 0;
    countTotalNodes(root, &nrOfNodes);
    int arrOfInorderTraversal[nrOfNodes];
    int index = 0;
    fillArrWithInorderTraversal(root, arrOfInorderTraversal, &index);
    checkIfBinaryTreeIsBST(arrOfInorderTraversal, nrOfNodes);
    
    
    // medium task 2
    int val;
    printf("\nDelete Node with value: ");
    scanf("%d", &val);
    root = deleteNode(root, val);
    displayBinaryTree(root, 0);
    
    // medium task 3
    if (isBalanced(root)) {
        printf("\nBinary tree is balanced\n");
    } else {
        printf("\nBinary tree is not balanced\n");
    }

    return 0;
}

