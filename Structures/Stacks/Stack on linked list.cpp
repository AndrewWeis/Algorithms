// Stack - LIFO "last in, first out
// Queue - FIFO "first in, first out


#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class stack
{
    Node* top;

public:

    stack() { top = NULL; }
    void push();
    void pop();
    void peek();
    void size();
    void display();
    ~stack();
};

void stack::push()
{
    Node* temp = new Node;
    cout << "Enter data: ";
    cin >> temp->data;
    temp->next = top;
    top = temp;
}

void stack::peek()
{
    if (top != NULL)
    {
        Node* temp = top;
        cout << "Top is: " << temp->data << endl;
    }
    else
        cout << "Stack is empty" << endl;
}

void stack::pop()
{
    if (top != NULL)
    {
        Node* temp = top;
        top = top->next;
        cout << "deleted: " << temp->data << endl;
        delete temp;
    }
    else
        cout << "Stack is empty" << endl;
}

void stack::size()
{
    Node* temp = top;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << "Size of stack is: " << count << endl;
}

void stack::display()
{
    Node* temp = top;
    cout << "Stack contains: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

stack::~stack()
{
    while (top != NULL)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    stack bubl;

    bubl.push();
    bubl.push();
    bubl.push();

    bubl.display();
    
    bubl.size();

    bubl.pop();
    bubl.peek();
    bubl.pop();
    bubl.pop();

    bubl.display();

    cout << "\n\n\n\n\n";

    return 0;
}
