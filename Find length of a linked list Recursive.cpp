Recursive Call:
In the recursive step, the function calls itself with the next node in the list.
The recursive call is made to the same function with the next node (node->next).
Termination Condition:
When the base case is met (i.e., when we reach the end of the list), the recursion stops, and the function starts returning values back up the call stack.
Counting Nodes:
At each step of the recursion, the function adds 1 to the result of the recursive call to count the current node.
This process continues until we reach the end of the list.
Return Value:
The value returned by the function represents the length of the linked list.*/


#include <iostream>

using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Define a LinkedList class
// Small change
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the end of the list
    void insert(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    // Find the length of the linked list (Recursive Approach)
    int lengthRecursive(Node* node) {
        if (!node) // Base case: If current node is null
            return 0;
        // Recursive call to count nodes in the remaining list
        return 1 + lengthRecursive(node->next);
    }

    // Wrapper function to start the recursive length calculation from the head
    int lengthRecursiveWrapper() {
        return lengthRecursive(head);
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedList llist;
    llist.insert(1);
    llist.insert(2);
    llist.insert(3);
    llist.insert(4);
    llist.insert(5);

    // Find the length of the linked list using recursive approach
    cout << "Length of the linked list (Recursive): " << llist.lengthRecursiveWrapper() << endl;  // Output: 5

    return 0;
}


/*Explanation:
The lengthRecursive function takes a pointer to the current node as an argument.
If the current node is null, it returns 0 (base case).
Otherwise, it makes a recursive call to the function with the next node in the list and adds 1 to the result of the
*/