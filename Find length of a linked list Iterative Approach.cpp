Iterative Approach:
To find the length of a linked list using an iterative approach, you can traverse the list node by node, counting each node encountered until you reach the end of the list (i.e., you encounter a null pointer). Here's a step-by-step explanation:
Start from the Head: Begin the traversal from the head of the linked list.
Initialize Length: Initialize a variable to keep track of the length of the linked list. Set it to 0 initially.
Traverse the List: Iterate through the list by moving to the next node in each iteration.
Count Nodes: Increment the length variable for each node encountered during the traversal.
End of List: Stop the traversal when you reach the end of the list (i.e., you encounter a null pointer).
Return Length: Once the traversal is complete, return the final length of the linked list.
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

// Define a LinkedList class
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

    // Find the length of the linked list (Iterative Approach)
    int lengthIterative() {
        int length = 0; // Initialize length variable
        Node* current = head;
        while (current) {
            length++; // Increment length for each node
            current = current->next;
        }
        return length;
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

    // Find the length of the linked list using iterative approach
    cout << "Length of the linked list (Iterative): " << llist.lengthIterative() << endl;  // Output: 5

    return 0;
}

/*
Explanation:
The lengthIterative function iterates through the linked list, counting each node encountered and incrementing the length variable accordingly.
It returns the final value of length once the traversal is complete, which represents the length of the linked list.
Recursive Approach:
In the recursive approach, we use a recursive function to find the length of the linked list. Here's how it works:
Base Case: If the current node is null (indicating the end of the list), return 0.
Recursive Call: Otherwise, make a recursive call to the function with the next node in the list.
Increment Count: Add 1 to the result of the recursive call to count the current node.
Return Length: Return the sum of 1 and the result of the recursive call (which represents the length of the remaining list).
*/