//Opertaion on Doubly linked list 
// Insertion at head and tail 
// Traversing the list

#include<iostream>
using namespace std;


//doubly linked list structure
class dllnode{
    public:
    int data;
    dllnode* prev;
    dllnode* next;

    dllnode(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void insertathead(dllnode* &head, int data){
    dllnode* temp = new dllnode(data);
    if(head == nullptr){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(dllnode* &head, int data){
    dllnode* temp = new dllnode(data);
    if(head == nullptr){
        head = temp;
    }
    dllnode* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = temp;
    temp->prev = current;

}

void printlist(dllnode* &head){
    dllnode* current = head;
    while(current != nullptr){
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL";
}

int main(){
    dllnode*  head = nullptr;
    insertathead(head, 10);
    insertathead(head, 20);
    insertathead(head, 30);
    insertattail(head, 5);
    printlist(head);
}
