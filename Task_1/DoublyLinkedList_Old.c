#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL, *tail = NULL, *curr;

void make_node(int data);
void push_back(int data);
void push_front(int data);
void insert(int pos, int data);
void pop_back();
void pop_front();
void delete(int pos);
void print_forward();
void print_backward();

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        push_back(data);
    }
    // insert(5, 99);
    // printf("\n\n");
    // pop_back();
    // pop_front();
    delete (6);
    print_forward();
    printf("\n\n");

    print_backward();
}

void delete(int pos)
{
    curr = head;
    if (pos == 1)
    {
        pop_front();
        return;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        if (curr == NULL)
            return;
        curr = curr->next;
    }
    if (curr == NULL)
        return;
    if (curr->next == NULL)
    {
        pop_back();
        return;
    }
    // int *temp = curr->prev;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}

void pop_front()
{

    head = head->next;
    head->prev = NULL;
}

void pop_back()
{
    tail = tail->prev;
    tail->next = NULL;
}

void insert(int pos, int data)
{
    make_node(data);
    pos -= 2;
    node *temp = head;
    for (int i = 0; i < pos; i++)
    {
        if (temp == NULL)
            return;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        push_back(data);
        return;
    }

    temp->next->prev = curr;
    curr->prev = temp;
    curr->next = temp->next;
    temp->next = curr;
}

void make_node(int data)
{
    curr = (node *)malloc(sizeof(node));
    curr->data = data;
}

void push_back(int data)
{
    make_node(data);
    curr->prev = tail;
    curr->next = NULL;
    if (head == NULL)
    {
        head = curr;
        tail = curr;
        return;
    }
    tail->next = curr;
    tail = curr;
}

void push_front(int data)
{
    make_node(data);
    curr->prev = NULL;
    curr->next = head;
    if (head == NULL)
    {
        head = curr;
        tail = curr;
        return;
    }
    head->prev = curr;
    head = curr;
}

void print_forward()
{
    for (curr = head; curr != NULL; curr = curr->next)
    {
        printf("%d ", curr->data);
    }
}

void print_backward()
{
    for (curr = tail; curr != NULL; curr = curr->prev)
    {
        printf("%d ", curr->data);
    }
}