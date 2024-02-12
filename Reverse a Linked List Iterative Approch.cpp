In the iterative approach, we reverse the linked list by traversing it iteratively and changing the next pointers of each node to point to the previous node instead of the next node
Initialize Pointers:
We maintain three pointers: prev, current, and next.
Initialize prev to nullptr (as it will become the last node in the reversed list).
Initialize current to the head of the original list.
Iterative Reversal:
Iterate through the list until current becomes nullptr.
Inside the loop:
Store the next node of current in the next pointer.
Update the next pointer of current to point to prev, effectively reversing the link.
Move prev to current, and current to next, preparing for the next iteration.
Update Head Pointer:
After the loop, prev will be pointing to the new head of the reversed list.
Update the head pointer of the list to prev.
*/


// Iterative function to reverse a linked list

#include <iostream>

using namespace std;

// Define a Node structure
// Small change
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Iterative function to reverse a linked list
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original linked list: ";
    printList(head);

    // Reverse the linked list iteratively
    head = reverseIterative(head);

    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}


/*
Explanation:
We initialize prev, current, and next pointers to perform the reversal.
Inside the loop, we reverse the link by updating the next pointer of the current node to point to the previous node.
We move the pointers prev, current, and next to prepare for the next iteration.
After the loop, prev will be pointing to the new head of the reversed list, so we update the head pointer accordingly.