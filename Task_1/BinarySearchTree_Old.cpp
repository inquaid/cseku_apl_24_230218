#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    
    int data;
    struct Node *left = NULL, *right = NULL;
} Node;
Node *head = NULL;

void insert(int data);
void insert_it(Node *curr, int val);
void inorder_it(Node *curr);
void inorder();
void preorder_it(Node *curr);
void preorder();
void postorder_it(Node *curr);
void postorder();
void bfs();
void bfs_it(Node *root);
bool search_it(Node *curr, int var);

bool search(int val);
bool search(int val)
{
    if (head->data == val)
    {
        return true;
    }
    return search_it(head, val);
}

bool search_it(Node *curr, int val)
{
    if (curr == NULL)
    {
        return false;
    }
    if (curr->data == val)
    {
        return true;
    }
    if (curr->data < val)
    {
        return search_it(curr->right, val);
    }
    else
    {
        return search_it(curr->left, val);
    }
    return false;
}

void bfs()
{
    bfs_it(head);
}

void bfs_it(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void insert(int data)
{
    Node *temp = new Node;
    // temp->left = temp->right = NULL;
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
        return;
    }

    insert_it(head, data);
}
void insert_it(Node *curr, int val)
{

    if (val <= curr->data)
    {
        if (curr->left == NULL)
        {
            Node *temp = new Node;
            temp->data = val;
            // temp->left = temp->right = NULL;
            curr->left = temp;
            return;
        }
        insert_it(curr->left, val);
    }
    else
    {
        if (curr->right == NULL)
        {
            Node *temp = new Node;
            temp->data = val;
            // temp->left = temp->right = NULL;
            curr->right = temp;
            return;
        }
        insert_it(curr->right, val);
    }
}

void inorder()
{
    inorder_it(head);
}
void inorder_it(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    if (curr->left != NULL)
    {
        inorder_it(curr->left);
    }

    cout << curr->data << " ";

    if (curr->right != NULL)
    {
        inorder_it(curr->right);
    }
}

void preorder()
{
    preorder_it(head);
}
void preorder_it(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    cout << curr->data << " ";
    if (curr->left != NULL)
    {
        preorder_it(curr->left);
    }

    if (curr->right != NULL)
    {
        preorder_it(curr->right);
    }
}

void postorder()
{
    postorder_it(head);
}
void postorder_it(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    if (curr->left != NULL)
    {
        postorder_it(curr->left);
    }

    if (curr->right != NULL)
    {
        postorder_it(curr->right);
    }
    cout << curr->data << " ";
}

int main()
{
    // head =new Node;
    // head->data = 41;
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
    // bfs();
    // cout << search(1);
    if (search(72))
    {
        cout << "Found\n";
    }
    else
        cout << "Not Found\n";
}