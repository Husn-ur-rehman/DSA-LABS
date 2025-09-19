#include <bits/stdc++.h>
using namespace std;

// Node class represents a single element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to create a new node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class manages the nodes
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void deleteDuplicates() {
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr ) {
            
            if (temp->data == temp->next->data) {

                Node* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } 
            else{
                temp = temp->next;
            }
        }
    }

    // Delete the first node with the given key
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // Case 1: Head node is the key
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        // Case 2: Find the key to be deleted
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // Case 3: Key was not found
        if (temp == nullptr) return;

        // Unlink the node and free memory
        prev->next = temp->next;
        delete temp;
    }

    // Search for a value in the list
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display all elements of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
     
};

// Main function
int main(){
    LinkedList list;

    list.insert(10);
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Initial Linked List: ";
    list.display();
    list.deleteDuplicates();
    cout<< "AFTER DELETION"<<endl;

    list.display();
    return 0;
}
