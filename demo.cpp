#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertathead(node* &head, int data) {
    node* temp = new node(data);
    if(head == nullptr) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertattail(node* &head, node* &tail, int data) {
    node* temp = new node(data);
    if(tail == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void deletefromhead(node* &head, node* &tail) {
    if(head == nullptr) {
        cout << "No list exists!" << endl;
    } else {
        node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }
}

void deletefromtail(node* &head, node* &tail) {
    if(tail == nullptr) {
        cout << "No list exists!" << endl;
        return;
    }
    if(head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    node* current = head;
    while(current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
}

void printlist(node* &head) {
    node* current = head;
    cout << "\nThe Current list is: ";
    while(current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;
    
    // Inserting multiple nodes at the head
    insertathead(head, 10);
    tail = head;
    insertathead(head, 20);
    insertathead(head, 30);
    insertathead(head, 40);
    
    // Print the list
    printlist(head);

    // Delete the head node and insert a node at the tail
    deletefromhead(head, tail);
    insertattail(head, tail, 5);
    
    // Print the list again
    printlist(head);

    // Delete the tail node and print the list again
    deletefromtail(head, tail);
    printlist(head);

    return 0;
}
