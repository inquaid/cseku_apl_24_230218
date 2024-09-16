/**
 * @file    BinarySearchTree_New.cpp
 * @brief   Implementation of a binary search tree with various traversal and search functions.
 *
 * @author  Azmain Inquaid Haque Turjo
 * @date    September 16, 2024
 *
 * @details This program demonstrates the insertion, traversal (inorder, preorder, postorder, BFS),
 *          and search operations on a binary search tree (BST). The tree stores integer values
 *          and provides both iterative and recursive functions for these operations.
 *
 *
 * @note    Ensure the tree is not empty before calling search or traversal operations.
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Structure representing a node in a binary search tree
typedef struct TreeNode {
    int data;
    struct TreeNode *left = NULL;
    struct TreeNode *right = NULL;
} TreeNode;

// Global pointer to the root node of the tree
TreeNode *root = NULL;

// Function declarations
void insert(int data);

void insertRecursive(TreeNode *current, int data);

void inorder();

void inorderTraversal(TreeNode *current);

void preorder();

void preorderTraversal(TreeNode *current);

void postorder();

void postorderTraversal(TreeNode *current);

void bfs();

void bfsTraversal(TreeNode *root);

bool search(int data);

bool searchRecursive(TreeNode *current, int data);

// Function to insert a value into the binary search tree

void insert(int data) {
    TreeNode *newNode = new TreeNode;
    newNode->data = data;

    if (root == NULL) {
        root = newNode; // Set as the root if the tree is empty
        return;
    }

    insertRecursive(root, data); // Insert recursively
}

// Helper function to recursively insert a node
void insertRecursive(TreeNode *current, int data) {
    if (data <= current->data) {
        if (current->left == NULL) {
            current->left = new TreeNode{data, NULL, NULL}; // Create a new node in the left subtree
            return;
        }
        insertRecursive(current->left, data); // Recursively insert in the left subtree
    } else {
        if (current->right == NULL) {
            current->right = new TreeNode{data, NULL, NULL}; // Create a new node in the right subtree
            return;
        }
        insertRecursive(current->right, data); // Recursively insert in the right subtree
    }
}

// Function to perform inorder traversal
void inorder() {
    inorderTraversal(root);
    cout << endl;
}

// Helper function for inorder traversal (Left, Root, Right)
void inorderTraversal(TreeNode *current) {
    if (current == NULL) {
        return;
    }

    inorderTraversal(current->left);
    cout << current->data << " ";
    inorderTraversal(current->right);
}

// Function to perform preorder traversal
void preorder() {
    preorderTraversal(root);
    cout << endl;
}

// Helper function for preorder traversal (Root, Left, Right)
void preorderTraversal(TreeNode *current) {
    if (current == NULL) {
        return;
    }

    cout << current->data << " ";
    preorderTraversal(current->left);
    preorderTraversal(current->right);
}

// Function to perform postorder traversal
void postorder() {
    postorderTraversal(root);
    cout << endl;
}

// Helper function for postorder travversal (Left, Right, Root)
void postorderTraversal(TreeNode *current) {
    if (current == NULL) {
        return;
    }

    postorderTraversal(current->left);
    postorderTraversal(current->right);
    cout << current->data << " ";
}

// Function to perform breadth-first search (BFS) traversal
void bfs() {
    bfsTraversal(root);
    cout << endl;
}

// Helper function for BFS traversal using a queue
void bfsTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (q.empty() == false) {
        TreeNode *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

// Function to search for a value in the tree
bool search(int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    return searchRecursive(root, data);
}

// Helper function to recursively search for a value
bool searchRecursive(TreeNode *current, int data) {
    if (current == NULL) {
        return false;
    }
    if (current->data == data) {
        return true;
    }
    if (current->data < data) {
        return searchRecursive(current->right, data);
    } else {
        return searchRecursive(current->left, data);
    }
    return false;
}

// Main function to demonstrate tree operations
int main() {
    // Insert elements into the tree
    insert(41);
    insert(20);
    insert(11);
    insert(29);
    insert(32);
    insert(65);
    insert(50);
    insert(91);
    insert(72);
    insert(99);

    // Perform traversals
    cout << "Inorder Traversal: ";
    inorder();

    cout << "Preorder Traversal: ";
    preorder();

    cout << "Postorder Traversal: ";
    postorder();

    // Perform BFS traversal
    cout << "BFS Traversal: ";
    bfs();

    // Search for a value in the tree
    int searchValue = 72;
    if (search(searchValue)) {
        cout << "Value " << searchValue << " found in the tree.\n";
    } else {
        cout << "Value " << searchValue << " not found in the tree.\n";
    }
}
