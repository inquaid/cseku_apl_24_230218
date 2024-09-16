/**
 * @file    doubly_linked_list.c
 * @brief   Implementation of basic operations on a doubly linked list.
 * 
 * @author  Azmain Inquaid Haque Turjo
 * @date    September 16, 2024
 * 
 * @details This program demonstrates the core operations of a doubly linked list, including 
 *          insertion, deletion from both ends, and traversal in both forward and backward directions.
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct node {
    int data; // Data held by the node
    struct node *next; // Pointer to the next node
    struct node *prev; // Pointer to the previous node
} node;

// Global pointers to head, tail, and current node
node *head = NULL, *tail = NULL, *curr;

// Function declarations
void make_node(int data);

void push_back(int data);

void push_front(int data);

void insert(int pos, int data);

void pop_back();

void pop_front();

void delete_node(int pos);

void print_forward();

void print_backward();

int main() {
    int n;
    printf("Enter the number of elements to add: ");
    scanf("%d", &n);

    // Adding elements to the list
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        push_back(data);
    }

    // Example operations (uncomment to use)
    // insert(5, 99);
    // pop_back();
    // pop_front();
    delete_node(6); // Delete element at position 6

    printf("\nList printed forward:\n");
    print_forward(); // Print the list from head to tail
    printf("\n\n");

    printf("List printed backward:\n");
    print_backward(); // Print the list from tail to head

    return 0;
}

/**
 * @brief   Creates a new node with the given data.
 * 
 * @param   data  The data to store in the new node.
 */
void make_node(int data) {
    curr = (node *) malloc(sizeof(node));
    curr->data = data;
}

/**
 * @brief   Adds a node to the back of the list.
 * 
 * @param   data  The data to insert.
 */
void push_back(int data) {
    make_node(data);
    curr->prev = tail;
    curr->next = NULL;

    if (head == NULL) // List is empty
    {
        head = curr;
        tail = curr;
    } else {
        tail->next = curr;
        tail = curr;
    }
}

/**
 * @brief   Adds a node to the front of the list.
 * 
 * @param   data  The data to insert.
 */
void push_front(int data) {
    make_node(data);
    curr->prev = NULL;
    curr->next = head;

    if (head == NULL) // List is empty
    {
        head = curr;
        tail = curr;
    } else {
        head->prev = curr;
        head = curr;
    }
}

/**
 * @brief   Inserts a node at the specified position in the list.
 * 
 * @param   pos   The position where the node will be inserted (1-based index).
 * @param   data  The data to insert.
 */
void insert(int pos, int data) {
    if (pos == 1) {
        push_front(data);
        return;
    }

    make_node(data);
    node *temp = head;

    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) // Position out of bounds
            return;
        temp = temp->next;
    }

    if (temp->next == NULL) {
        push_back(data);
        return;
    }

    // Insert node between temp and temp->next
    curr->next = temp->next;
    curr->prev = temp;
    temp->next->prev = curr;
    temp->next = curr;
}

/**
 * @brief   Deletes the node at the specified position in the list.
 * 
 * @param   pos  The position of the node to delete (1-based index).
 */
void delete_node(int pos) {
    curr = head;

    if (pos == 1) {
        pop_front();
        return;
    }

    for (int i = 1; i < pos; i++) {
        if (curr == NULL) // Position out of bounds
            return;
        curr = curr->next;
    }

    if (curr == NULL) // Position out of bounds
        return;

    if (curr->next == NULL) {
        pop_back();
        return;
    }

    // Remove the node from the list
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}

/**
 * @brief   Removes the front node from the list.
 */
void pop_front() {
    if (head == NULL) // List is empty
        return;

    node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

/**
 * @brief   Removes the back node from the list.
 */
void pop_back() {
    if (tail == NULL) // List is empty
        return;

    node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

/**
 * @brief   Prints the elements of the list from head to tail.
 */
void print_forward() {
    for (curr = head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
}

/**
 * @brief   Prints the elements of the list from tail to head.
 */
void print_backward() {
    for (curr = tail; curr != NULL; curr = curr->prev) {
        printf("%d ", curr->data);
    }
}
