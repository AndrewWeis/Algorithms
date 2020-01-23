// Single linked list с вспомогательный элементом head

// Списки медленне работают с операциями доступа к данным чем массивы, но они быстрее если нужно убирать добавлять как-то изменять количесвто элементов

// Операция добавления спереди (push) выполняется в 4 шага, а именно
// Выделение памяти под новый node -> Присваивание значения -> присваивание указателя -> присваивание head указателя на node
// Особенность: **Node head_ref - это указатель на указатель, в котором хранится адресс того, на что указывает head 
// Передаем в функцию именно адресс (&head)
// *head - это адресс следующего node, другими словами того node, на который указывает head.
// Пример head -> Null  (push)  head -> node1 -> Null (push) head -> node2 -> node1 -> Null

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

int main()
{
    Node* head = NULL;

    append(&head, 4);   
    push(&head, 3);
    append(&head, 5);
    push(&head, 1);
    insertAfter(head, 2);

    // head -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    cout << "Created Linked list is: ";
    printList(head);
    cout << "\n\n\n\n\n\n";
    return 0;
}
