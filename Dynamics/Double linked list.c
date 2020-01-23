#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

void deleteByPosition(Node** head_ref, int position)
{
    // first Node is position 0 
    if (*head_ref == NULL) return;

    Node* prev = NULL;
    Node* temp = *head_ref;
    int count = 0;

    if (position == 0)
    {
        *head_ref = temp->next;
        delete(temp);
        return;
    }

    while (temp != NULL && count != position)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void deleteByKey(Node** head_ref, int key)
{
    Node* prev = NULL;
    Node* temp = *head_ref;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

int main()
{
    Node* head = NULL;

    append(&head, 4);   
    push(&head, 3);
    append(&head, 5);
    push(&head, 1);
    insertAfter(head, 2);
    // head -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    deleteByKey(&head, 3);
    // head -> 1 -> 2 -> 4 -> 5 -> NULL
    deleteByPosition(&head, 2);
    // head -> 1 -> 2 -> 5 -> NULL
    
    cout << "Created Linked list is: ";
    printList(head);
    cout << "\n\n\n\n\n\n";
    return 0;
} 
