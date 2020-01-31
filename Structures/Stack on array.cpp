#include <iostream>

using namespace std;

#define MAX 3 

class Stack {
    int top;

public:
    int a[MAX]; // Maximum size of Stack 

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        cout << x << " removed from stack\n";
        return x;
    }
}

int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int Stack::size()
{
    return top + 1;
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is " << s.peek() << endl;
    cout << "Stack size is " << s.size() << endl;

    s.pop();
    s.pop();
    s.pop();

    if (s.isEmpty())
        cout << "Stack is empty! " << endl;
    else
        cout << "Stack isn't empty! " << endl;

    cout << "\n\n\n\n\n";

    return 0;
}
