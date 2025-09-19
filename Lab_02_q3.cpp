#include <bits/stdc++.h>
using namespace std;

// Node class
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

    Node* mergeTwoLists(Node* list1, Node* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        Node* result = nullptr;
        if (list1->data <= list2->data) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        return result;
    }

    Node* sortListHelper(Node* node) {
        if (!node || !node->next) return node;

        // Split into two halves
        Node* slow = node;
        Node* fast = node->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* rightHalf = slow->next;
        slow->next = nullptr; // break into halves
        Node* leftHalf = node;

        Node* leftSorted = sortListHelper(leftHalf);
        Node* rightSorted = sortListHelper(rightHalf);

        return mergeTwoLists(leftSorted, rightSorted);
    }

public:

    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteDuplicates() {
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->data == temp->next->data) {
                Node* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } else {
                temp = temp->next;
            }
        }
    }

    // Delete a node by key
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return;

        prev->next = temp->next;
        delete temp;
    }

    // Search for a key
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Public sort function
    void sortList() {
        head = sortListHelper(head);
    }
};

// Main function
int main() {
    LinkedList list;

    list.insert(30);
    list.insert(10);
    list.insert(20);
    list.insert(10);

    cout << "Initial Linked List: ";
    list.display();

    list.sortList();

    cout << "Sorted Linked List: ";
    list.display();

    return 0;
}
