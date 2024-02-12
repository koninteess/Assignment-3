In the recursive approach, we reverse the linked list by recursively calling a function to reverse the sublist starting from the second node. Here's how it works:
Base Case:
If the list is empty or has only one node, return the head pointer as is.
Recursive Call:
Recursively call the function to reverse the sublist starting from the second node.
Reverse Links:
Reverse the link between the second node (current) and the first node (head) by setting the next pointer of the second node to point to the first node.
Set Head Pointer:
Set the next pointer of the head node to nullptr to mark it as the last node in the reversed list.
Return New Head:
Return the head pointer of the reversed list.
*/
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
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Recursive function to reverse a linked list
Node* reverseRecursive(Node* head) {
    // Base case: if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursively reverse the sublist starting from the second node
    Node* reversedHead = reverseRecursive(head->next);

    // Reverse the link between the second node (current) and the first node (head)
    head->next->next = head;

    // Set the next pointer of the head node to nullptr
    head->next = nullptr;

    // Return the head pointer of the reversed list
    return reversedHead;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Reverse the linked list recursively
    head = reverseRecursive(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
