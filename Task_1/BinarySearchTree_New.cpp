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
/**
 * @brief   Inserts a value into the binary search tree.
 *
 * @details This function inserts a new value into the binary search tree. If the tree is empty,
 *          the new value becomes the root. Otherwise, the value is inserted into the correct
 *          position in the tree based on binary search tree properties.
 *
 * @param   data The integer value to insert into the tree.
 */
void insertRecursive(TreeNode *current, int data);
/**
 * @brief   Recursively inserts a value into the binary search tree.
 *
 * @param   current The current node being traversed.
 * @param   data    The integer value to insert into the tree.
 */
void inorder();
/**
 * @brief   Performs an inorder traversal of the binary search tree.
 *
 * @details This function prints the nodes of the binary search tree in inorder sequence:
 *          Left subtree, Root, Right subtree.
 */
void inorderTraversal(TreeNode *current);
/**
 * @brief   Recursively performs inorder traversal of the binary search tree.
 *
 * @param   current The current node being traversed.
 */
void preorder();
/**
 * @brief   Performs a preorder traversal of the binary search tree.
 *
 * @details This function prints the nodes of the binary search tree in preorder sequence:
 *          Root, Left subtree, Right subtree.
 */
void preorderTraversal(TreeNode *current);
/**
 * @brief   Recursively performs preorder traversal of the binary search tree.
 *
 * @param   current The current node being traversed.
 */
void postorder();
/**
 * @brief   Performs a postorder traversal of the binary search tree.
 *
 * @details This function prints the nodes of the binary search tree in postorder sequence:
 *          Left subtree, Right subtree, Root.
 */
void postorderTraversal(TreeNode *current);
/**
 * @brief   Recursively performs postorder traversal of the binary search tree.
 *
 * @param   current The current node being traversed.
 */
void bfs();
/**
 * @brief   Performs a breadth-first search (BFS) traversal of the binary search tree.
 *
 * @details This function traverses the binary search tree level by level using a queue,
 *          and prints the nodes in BFS order.
 */
void bfsTraversal(TreeNode *root);
/**
 * @brief   Performs BFS traversal using a queue.
 *
 * @param   root The root node of the binary search tree.
 */
bool search(int data);
/**
 * @brief   Searches for a value in the binary search tree.
 *
 * @details This function searches for a given integer value in the binary search tree.
 *          It returns true if the value is found, false otherwise.
 *
 * @param   data The integer value to search for in the tree.
 *
 * @return  true if the value is found, false otherwise.
 */
bool searchRecursive(TreeNode *current, int data);
/**
 * @brief   Recursively searches for a value in the binary search tree.
 *
 * @param   current The current node being traversed.
 * @param   data    The integer value to search for in the tree.
 *
 * @return  true if the value is found, false otherwise.
 */

// Function to insert a value into the binary search tree
void insert(int data) {
    TreeNode *newNode = new TreeNode;  // Allocate memory for a new node
    newNode->data = data;  // Set the data for the new node

    if (root == NULL) {
        root = newNode;  // If the tree is empty, set the new node as root
        return;
    }

    insertRecursive(root, data);  // Call recursive helper to insert the data at the correct position
}

// Recursive helper function to insert a value into the binary search tree
void insertRecursive(TreeNode *current, int data) {
    if (data <= current->data) {  // If the data is less than or equal to the current node's data
        if (current->left == NULL) {
            current->left = new TreeNode{data, NULL, NULL};  // Create a new node and insert it to the left
            return;
        }
        insertRecursive(current->left, data);  // Recursively insert in the left subtree
    } else {  // If the data is greater than the current node's data
        if (current->right == NULL) {
            current->right = new TreeNode{data, NULL, NULL};  // Create a new node and insert it to the right
            return;
        }
        insertRecursive(current->right, data);  // Recursively insert in the right subtree
    }
}

// Function to perform inorder traversal (Left, Root, Right)
void inorder() {
    inorderTraversal(root);  // Call recursive helper for inorder traversal
    cout << endl;
}

// Recursive helper function for inorder traversal
void inorderTraversal(TreeNode *current) {
    if (current == NULL) {
        return;  // Base case: stop if current node is null
    }

    inorderTraversal(current->left);  // Traverse the left subtree
    cout << current->data << " ";  // Visit the root (current node)
    inorderTraversal(current->right);  // Traverse the right subtree
}

// Function to perform preorder traversal (Root, Left, Right)
void preorder() {
    preorderTraversal(root);  // Call recursive helper for preorder traversal
    cout << endl;
}

// Recursive helper function for preorder traversal
void preorderTraversal(TreeNode *current) {
    if (current == NULL) {
        return;  // Base case: stop if current node is null
    }

    cout << current->data << " ";  // Visit the root (current node)
    preorderTraversal(current->left);  // Traverse the left subtree
    preorderTraversal(current->right);  // Traverse the right subtree
}

// Function to perform postorder traversal (Left, Right, Root)
void postorder() {
    postorderTraversal(root);  // Call recursive helper for postorder traversal
    cout << endl;
}

// Recursive helper function for postorder traversal
void postorderTraversal(TreeNode *current) {
    if (current == NULL) {
        return;  // Base case: stop if current node is null
    }

    postorderTraversal(current->left);  // Traverse the left subtree
    postorderTraversal(current->right);  // Traverse the right subtree
    cout << current->data << " ";  // Visit the root (current node)
}

// Function to perform breadth-first search (BFS) traversal
void bfs() {
    bfsTraversal(root);  // Call helper function to traverse the tree using BFS
    cout << endl;
}

// Helper function for BFS traversal using a queue
void bfsTraversal(TreeNode *root) {
    if (root == NULL) {
        return;  // Return if the tree is empty
    }

    queue<TreeNode *> q;  // Create a queue to hold nodes for BFS
    q.push(root);  // Start with the root node

    while (!q.empty()) {  // Loop until the queue is empty
        TreeNode *current = q.front();  // Get the front node in the queue
        q.pop();  // Remove the front node

        cout << current->data << " ";  // Visit the current node

        if (current->left != NULL) {  // If left child exists, add it to the queue
            q.push(current->left);
        }
        if (current->right != NULL) {  // If right child exists, add it to the queue
            q.push(current->right);
        }
    }
}

// Function to search for a value in the tree
bool search(int data) {
    if (root == NULL) {
        return false;  // If the tree is empty, return false
    }
    if (root->data == data) {
        return true;  // If the root contains the value, return true
    }
    return searchRecursive(root, data);  // Recursively search for the value
}

// Recursive helper function to search for a value in the tree
bool searchRecursive(TreeNode *current, int data) {
    if (current == NULL) {
        return false;  // Base case: value not found
    }
    if (current->data == data) {
        return true;  // Value found at the current node
    }
    if (current->data < data) {
        return searchRecursive(current->right, data);  // Search the right subtree if data is greater
    } else {
        return searchRecursive(current->left, data);  // Search the left subtree if data is smaller
    }
    return false;  // Default return false (unreachable in normal conditions)
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
