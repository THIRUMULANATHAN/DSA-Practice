#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct SinglyLinkedList {
    Node* head;
    Node* tail;
};

void initList(SinglyLinkedList* list) {
    list->head = nullptr;
    list->tail = nullptr;
}

Node* createNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

void insert(SinglyLinkedList* list, int data) {
    Node* node = createNode(data);
    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void display(SinglyLinkedList* list) {
    Node* temp = list->head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insertAtBeginning(SinglyLinkedList* list, int data) {
    Node* node = createNode(data);

    if (list->head == nullptr) { 
        list->head = list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
}

void insertAt(SinglyLinkedList* list, int data, int position) {
    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    Node* node = createNode(data);
    Node* temp = list->head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return;
    node->next = temp->next;
    temp->next = node;
    if (node->next == nullptr) list->tail = node;
}

void deleteAtBeginning(SinglyLinkedList* list) {
    if (list->head == nullptr) return;
    Node* temp = list->head;
    list->head = list->head->next;
    delete temp;
    if (list->head == nullptr) list->tail = nullptr;
}

void deleteAtEnd(SinglyLinkedList* list) {
    if (list->head == nullptr) return;
    if (list->head == list->tail) {
        delete list->head;
        list->head = list->tail = nullptr;
        return;
    }
    Node* temp = list->head;
    while (temp->next != list->tail) {
        temp = temp->next;
    }
    delete list->tail;
    temp->next = nullptr;
    list->tail = temp;
}

void deleteAt(SinglyLinkedList* list, int position) {
    if (list->head == nullptr) return;
    if (position == 0) {
        deleteAtBeginning(list);
        return;
    }
    Node* temp = list->head;
    for (int i = 0; i < position - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) return;
    Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == list->tail) list->tail = temp;
    delete delNode;
}

int getSize(SinglyLinkedList* list) {
    int n = 0;
    Node* temp = list->head;
    while (temp) {
        n++;
        temp = temp->next;
    }
    return n;
}

void reverse(SinglyLinkedList* list) {
    Node* curr = list->head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->tail = list->head;
    list->head = prev;
}

void destroyList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list->head = list->tail = nullptr;
}

int main() {
    SinglyLinkedList list;
    initList(&list);
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 40);
    insert(&list, 50);
    cout << "Original List:\n";
    display(&list);
    cout << "Reversed List:\n";
    reverse(&list);
    display(&list);
    cout << "Size: " << getSize(&list) << endl;
    destroyList(&list);
    return 0;
}
