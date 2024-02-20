#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void handleList() {
    int size, val;
    cout << "Enter the size of the list: ";
    cin >> size;

    list<int> myList;
    cout << "Enter " << size << " integers for the list:\n";
    for (int i = 0; i < size; ++i) {
        cin >> val;
        myList.push_back(val);
    }

    cout << "List contents: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;
}

void handleLinkedList() {
    int size, val;
    cout << "Enter the size of the linked list: ";
    cin >> size;

    struct Node {
        int data;
        Node* next;
    };

    Node* head = nullptr;
    Node* temp = nullptr;
    cout << "Enter " << size << " integers for the linked list:\n";
    for (int i = 0; i < size; ++i) {
        cin >> val;
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    cout << "Linked list contents: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void handleArray() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> myArray(size);
    cout << "Enter " << size << " integers for the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> myArray[i];
    }

    cout << "Array contents: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;
}

void handleStack() {
    int size, val;
    cout << "Enter the size of the stack: ";
    cin >> size;

    stack<int> myStack;
    cout << "Enter " << size << " integers for the stack:\n";
    for (int i = 0; i < size; ++i) {
        cin >> val;
        myStack.push(val);
    }

    cout << "Stack contents: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
}

void handleQueue() {
    int size, val;
    cout << "Enter the size of the queue: ";
    cin >> size;

    queue<int> myQueue;
    cout << "Enter " << size << " integers for the queue:\n";
    for (int i = 0; i < size; ++i) {
        cin >> val;
        myQueue.push(val);
    }

    cout << "Queue contents: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
}

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void handleBinaryTree() {
    int size, val;
    cout << "Enter the number of elements for the binary tree: ";
    cin >> size;

    TreeNode* root = nullptr;
    cout << "Enter " << size << " integers for the binary tree:\n";
    for (int i = 0; i < size; ++i) {
        cin >> val;
        insert(root, val);
    }

    cout << "In-order traversal of binary tree: ";
    inOrderTraversal(root);
    cout << endl;
}

int main() {
    int choice;
    cout << "Choose a data structure to interact with:\n";
    cout << "1. List\n";
    cout << "2. Linked List\n";
    cout << "3. Array\n";
    cout << "4. Stack\n";
    cout << "5. Queue\n";
    cout << "6. Binary Tree\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            handleList();
            break;
        case 2:
            handleLinkedList();
            break;
        case 3:
            handleArray();
            break;
        case 4:
            handleStack();
            break;
        case 5:
            handleQueue();
            break;
        case 6:
            handleBinaryTree();
            break;
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}