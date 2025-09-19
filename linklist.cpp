#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    Node* getHead() { return head; }

    // Insert at end
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display
    void display(Node* node = nullptr) {
        if (!node) node = head;
        while (node) {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << "NULL\n";
    }

    // 1. Merge two sorted lists
    Node* mergeTwoLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    Node* head = nullptr;

    if (list1->data < list2->data) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    Node* tail = head;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return head;
    }

    // 2. Delete duplicates from sorted list
    Node* deleteDuplicates(Node* head) {
        Node* temp = head;
        while (temp->next != nullptr) {
            
            if (temp->data == temp->next->data) {

                Node* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } 
            else{
                temp = temp->next;
            }
        }
        return head;
    }

    // Helper for merge sort
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 3. Sort list using merge sort
    Node* sortList(Node* head) {
        if (!head || !head->next) return head;
        Node* mid = findMiddle(head);
        Node* right = mid->next;
        mid->next = nullptr;
        Node* left = sortList(head);
        right = sortList(right);
        return merge(left, right);
    }

    // 4. Check if palindrome
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // Find middle
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node* prev = nullptr;
        Node* curr = slow->next;
        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Compare
        Node* p1 = head;
        Node* p2 = prev;
        while (p2) {
            if (p1->data != p2->data) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    // 5. Circular Queue using Linked List
    class CircularQueue {
    private:
        Node* front;
        Node* rear;
    public:
        CircularQueue() {
            front = rear = nullptr;
        }
        void enqueue(int data) {
            Node* newNode = new Node(data);
            if (!rear) {
                front = rear = newNode;
                rear->next = front;
            } else {
                rear->next = newNode;
                rear = newNode;
                rear->next = front;
            }
        }
        void dequeue() {
            if (!front) return;
            if (front == rear) {
                delete front;
                front = rear = nullptr;
            } else {
                Node* temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
        }
        void display() {
            if (!front) return;
            Node* temp = front;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    };

    // 6. Stack using Linked List
    class Stack {
    private:
        Node* top;
    public:
        Stack() { top = nullptr; }
        void push(int data) {
            Node* newNode = new Node(data);
            newNode->next = top;
            top = newNode;
        }
        void pop() {
            if (!top) return;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        int peek() {
            if (!top) return -1;
            return top->data;
        }
        bool isEmpty() { return top == nullptr; }
    };
};

int main() {
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(1);
    list.insert(3);

    cout << "Original List: ";
    list.display();

    Node* sortedHead = list.sortList(list.getHead());
    cout << "Sorted List: ";
    list.display(sortedHead);

    cout << "Is Palindrome? " << (list.isPalindrome(sortedHead) ? "Yes" : "No") << endl;

    return 0;
}
