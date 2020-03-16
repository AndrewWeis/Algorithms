#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next, *prev;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
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
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head_ref; 

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    delete del;
}

void deleteByPosition(Node** head_ref, int position)
{
    // first Node is position 0 
    if (*head_ref == NULL || position <= 0)
        return;

    Node* current = *head_ref;

    for (int i = 0; current != NULL && i < position; i++)
        current = current->next;

    if (current == NULL)
        return;

    deleteNode(head_ref, current);
}

void deleteByKey(Node** head_ref, int key)
{
    if ((*head_ref) == NULL)
        return;

    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL)
    {
        if (current->data == key)
        {
            next = current->next;
            deleteNode(head_ref, current);
            current = next;
        }
        else
            current = current->next;
    }
}

void printList(struct Node* node)
{
    Node* last = NULL;
    cout << "\nTraversal in forward direction: ";
    while (node != NULL) {
        cout << " " << node->data;
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction: ";
    while (last != NULL) {
        cout << " " << last->data;
        last = last->prev;
    }
}

int main()
{
    Node* head = NULL;

    push(&head, 2);
    insertAfter(head, 3);
    push(&head, 1);
    append(&head, 4);
    append(&head, 5);
    // 1 -> 2 -> 3 -> 4 -> 5 

    deleteByPosition(&head, 1);
    deleteByKey(&head, 3);
    // 1 -> 4 -> 5

    
    cout << "Created DDL is: ";
    printList(head);
    cout << "\n\n\n\n\n\n";
    return 0;
} 
