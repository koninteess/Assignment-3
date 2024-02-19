#include <iostream>
#include <string>
// Creating a class name person to 
class Person {
public:
    std::string name; // declearing the required variables
    Person* spouse;
    Person* left_child;   // Represents the left child or the person's child from a previous relationship
    Person* right_child;  // Represents the right child or the person's child from a current relationship
    // creating the constructor for the object creation
    Person(std::string n) : name(n), spouse(nullptr), left_child(nullptr), right_child(nullptr) {}
};
// Creating the class family 
class FamilyTree {
public:
    Person* root; // Declearing the variable
    // creating a constructor
    FamilyTree() : root(nullptr) {}

    //  Creating a new Function to add a new family member
    void addFamilyMember(std::string name) {
        if (!root) {
            root = new Person(name);
        }
        else {
            addFamilyMemberRecursive(root, name);
        }
    }

    //  Creating a Function to add a family member recursively
    void addFamilyMemberRecursive(Person* currentPerson, std::string name) {
        if (!currentPerson->left_child) {
            currentPerson->left_child = new Person(name);
            currentPerson->left_child->spouse = currentPerson;
        }
        else if (!currentPerson->right_child) {
            currentPerson->right_child = new Person(name);
            currentPerson->right_child->spouse = currentPerson;
        }
        else {
            // checking if the left sub tree  are already occupied, try to add to the left child's subtree
            addFamilyMemberRecursive(currentPerson->left_child, name);
        }
    }

    //  creating a Function to display the family tree
    void displayFamilyTree(Person* currentPerson, int depth = 0) {
        if (currentPerson) {
            displayFamilyTree(currentPerson->left_child, depth + 1);

            // Indent based on depth
            for (int i = 0; i < depth; ++i) {
                std::cout << "   ";
            }

            // Display the person's name
            std::cout << currentPerson->name;
            if (currentPerson->spouse) {
                std::cout << " (Spouse: " << currentPerson->spouse->name << ")";
            }
            std::cout << std::endl;

            displayFamilyTree(currentPerson->right_child, depth + 1);
        }
    }
};
// creating a main function to perform the operations of the binary tree
int main() {
    FamilyTree familyTree;

    int familySize;
    std::cout << "Enter the number of family members: ";
    std::cin >> familySize;

    for (int i = 0; i < familySize; ++i) {
        std::string name;
        std::cout << "Enter name for family member " << i + 1 << ": ";
        std::cin >> name;
        familyTree.addFamilyMember(name);
    }

    std::cout << "\nFamily Tree:" << std::endl;
    familyTree.displayFamilyTree(familyTree.root);

    return 0;
}
