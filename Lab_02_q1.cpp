#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Linklist{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode *head =nullptr;

        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }else{
            head = list2;
            list2 = list2->next;
        }
        ListNode *tail=head;

        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next =list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;

        }
        if(list1){
            tail->next = list1;
        } 
        else{
            tail->next = list2;
        }
        return head;
    }
};
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> vals1 = {1, 3, 5};
    vector<int> vals2 = {2, 4, 6};

    ListNode* ll1 = createList(vals1);
    ListNode* ll2 = createList(vals2);

    cout << "List 1: ";
    printList(ll1);

    cout << "List 2: ";
    printList(ll2);

    Linklist obj;
    ListNode* mergedlist = obj.mergeTwoLists(ll1, ll2);

    cout << "Merged List: ";
    printList(mergedlist);

    return 0;
}



