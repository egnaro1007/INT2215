#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->data = data;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    }
    else {
        SinglyLinkedListNode* pointer = head;
        while (pointer->next != nullptr) {
            pointer = pointer->next;
        }
        pointer->next = newNode;
    }
    return head;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (llist == nullptr) {
        llist = newNode;
    }
    else {
        SinglyLinkedListNode* pointer = llist;
        for (int i = 0; i < position - 1; i++) {
            pointer = pointer->next;
        }
        newNode->next = pointer->next;
        pointer->next = newNode;
    }

    return llist;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (llist == nullptr) {
        return llist;
    }
    else {
        SinglyLinkedListNode* pointer = llist;   
        for (int i = 0; i < position - 1; i++) {
            pointer = pointer->next;
        }
        if (pointer->next->next == nullptr) {
            pointer->next = nullptr;
        }
        else{pointer->next = pointer->next->next;
        }
        
        return llist;
    }
}

void reversePrint(SinglyLinkedListNode* llist) {
    if (llist == nullptr) {
        return;
    }
    else {
        reversePrint(llist->next);
        cout << llist->data << endl;
    }
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == nullptr && head2 == nullptr) {
        return true;
    }
    if (head1 == nullptr || head2 == nullptr) {
        return false;
    }

    if (head1->data == head2->data) {
        return compare_lists(head1->next, head2->next);
    }
    else {
        return false;
    }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    if (head1->data < head2->data) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
      	SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();

    return 0;
}
