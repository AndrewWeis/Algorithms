Algorithm:

Step 1: Take the elements input in an array.
Step 2: Create a Binary search tree by inserting data items from the array into the
        binary search tree.
Step 3: Perform in-order traversal on the tree to get the elements in sorted order.

Average Case Time Complexity : O(n log n) Adding one item to a Binary Search tree on average takes O(log n) time. 
Therefore, adding n items will take O(n log n) time

Worst Case Time Complexity : O(n2). The worst case time complexity of Tree Sort can be improved by using a self-balancing binary search tree like Red Black Tree, AVL Tree.
Using self-balancing binary tree Tree Sort will take O(n log n) time to sort the array in worst case.

#include <iostream> 

using namespace std;

class Node
{
public:
    int data;
    Node* left, * right;
};

Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new
   Node with given key in BST */
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Stores inoder traversal of the BST in arr[] 
void storeSorted(Node* root, int arr[], int& i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->data;
        storeSorted(root->right, arr, i);
    }
}

// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(int arr[], int n)
{
    Node* root = NULL;

    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
        insert(root, arr[i]);

    int i = 0;
    storeSorted(root, arr, i);
}

int main()
{
    int arr[] = { 5, 4, 7, 2, 11 };  
    int n = sizeof(arr) / sizeof(arr[0]);

    treeSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
