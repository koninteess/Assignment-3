Start from the head of the linked list.
Traverse the linked list one node at a time.
At each node, compare the value of the current node with the target value.
If the values match, return true (indicating that the element is found).
If the end of the linked list is reached without finding the element, return false.
Iterative Approach :
Advantages:
Generally more memory - efficient than recursion, as it does not involve additional function calls.
May be more intuitive for some programmers, especially those familiar with loop - based algorithms.
Disadvantages :
    Can be more complex to implement and understand, especially for more intricate operations.
    May lead to code duplication if the same logic needs to be repeated in multiple places.
    Recursive Approach :
Advantages:
Often more concise and easier to understand for certain problems, especially those that naturally lend themselves to recursive solutions.
Can be elegant and expressive for algorithms where recursion simplifies the problem - solving process.
Disadvantages :
    May incur additional memory overhead due to recursive function calls, potentially leading to stack overflow errors for very large input sizes.
    Can be less efficient in terms of runtime performance compared to iterative solutions, especially for large input sizes due to the overhead of function calls.
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

    // Private member function for recursive search
    bool searchRecursive(Node* node, int key) {
        if (!node)
            return false;
        if (node->data == key)
            return true;
        return searchRecursive(node->next, key);
    }

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

    // Iterative search for an element
    bool searchIterative(int key) {
        Node* current = head;
        while (current) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }

    // Wrapper function to start the recursive search from the head
    bool search(int key) {
        return searchRecursive(head, key);
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

    // Search for an element (e.g., 3) using iterative approach
    cout << "Iterative Search:" << endl;
    cout << boolalpha << llist.searchIterative(3) << endl;  // Output: true

    // Search for an element (e.g., 6) using recursive approach
    cout << "Recursive Search:" << endl;
    cout << boolalpha << llist.search(6) << endl;  // Output: false

    return 0;
}
