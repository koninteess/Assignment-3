#include <iostream>
#include <string>
// Creating the new class name as shopping crt 
class ShoppingItem {
public:
    std::string name; // creating the variables 
    ShoppingItem* next;
    // Creating a constructor for object creation
    ShoppingItem(std::string itemName) : name(itemName), next(nullptr) {}
};
// Creaging a another class for the implementation.
class ShoppingList {
public:
    ShoppingItem* head;

    ShoppingList() : head(nullptr) {}

    //creating a  Function to add an item to the shopping list
    void addItem(std::string itemName) {
        ShoppingItem* newItem = new ShoppingItem(itemName);
        newItem->next = head;
        head = newItem;
    }

    // Creating a Function to display the shopping list
    void displayList() {
        ShoppingItem* current = head;
        while (current) {
            std::cout << current->name << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

// Ceaginga main function
int main() {
    ShoppingList shoppingList;

    int listSize;
    // taking input from the user
    std::cout << "Enter the number of items in the shopping list: ";
    std::cin >> listSize; // 
    // iterating the items that need to store using loop
    for (int i = 0; i < listSize; ++i) {
        std::string item;
        std::cout << "Enter item " << i + 1 << ": ";
        std::cin >> item;
        shoppingList.addItem(item);
    }
    // printing the number of the list items that are stored.

    std::cout << "\nShopping List:" << std::endl;
    shoppingList.displayList(); // calling the function to print the list of the items that are stored.

    return 0;
}
