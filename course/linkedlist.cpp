#include <iostream>
struct Node {
    int value;
    Node* next;
};
// convert a1 -> a2 -> a3 -> ... -> an -> b1 -> b2 -> b3 -> ... -> bn to a1 -> b1 -> a2 -> b2 -> a3 -> b3 -> ... -> an -> bn
Node* convert (Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head2 = slow->next;
    slow->next = nullptr;
    Node* p1 = head;
    Node* p2 = head2;
    while (p1 != nullptr && p2 != nullptr) {
        Node* temp1 = p1->next;
        Node* temp2 = p2->next;
        p1->next = p2;
        p2->next = temp1;
        p1 = temp1;
        p2 = temp2;
    }
    return head;
}

Node* insert(Node* head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return head;
    }

    Node* pointer = head;
    while (pointer->next != nullptr) {
        if (pointer->value < newNode->value && newNode->value < pointer->next->value) {
            newNode->next = pointer->next;
            pointer->next = newNode;
            return head;
        }
        if (pointer->value > newNode->value && newNode->value > pointer->next->value) {
            newNode->next = pointer->next;
            pointer->next = newNode;
            return head;
        }
        pointer = pointer->next;
    }
}

void print (Node* head) {
    Node* pointer = head;
    while (pointer != nullptr) {
        std::cout << pointer->value << " ";
        pointer = pointer->next;
    }
}

void printLast(Node* head, int k) {
    Node* pointer = new Node;
    // Count number of nodes
    int numberOfNodes = 0;
    pointer = head;
    while (pointer != nullptr) {
        numberOfNodes++;
        pointer = pointer->next;
    }
    // Skip first n - k nodes
    int numberOfSkippedNodes = numberOfNodes - k;
    pointer = head;
    for (int i = 0; i < numberOfSkippedNodes; i++) {
        pointer = pointer->next;
    }
    // Print the rest k nodes
    while (pointer != nullptr) {
        std::cout << pointer->value << " ";
        pointer = pointer->next;
    }
}