#include<iostream>
#include<algorithm>

using namespace std;

//creating the structure of the node
class node {
public:
    int data;
    node* next;

    node(int data) { //constructor
        this->data = data;
        this->next = nullptr;
    }

    ~node(){  //destructor
    int data = this->data;
    if(this->next != nullptr){
        delete next;
        this->next = nullptr;
        }
    cout << "\nMemory is free for the data : "<< data << endl;
    }
};

//function of inserting at beginning
void insertatbeg(node* &head, int data) {
    node* temp = new node(data);
    if (head == nullptr) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

// function for inserting at end
void insertatend(node* &tail, int data){
    node* temp = new node(data);
    if(tail == nullptr){
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

// function for insertion at given position
void insertatposition(node* &head, node* &tail, int pos, int data){
    node* temp = head;

    if(pos == 1){ //insertion at begining also updating the head
        insertatbeg(head, data);
        return;
    }

    int cnt =1;
    while(cnt < pos-1){ //to reach one previous node where we have to insert
        temp = temp->next;
        cnt++;
    }

    if(temp->next == nullptr){ //if element is inserting at last update tail
        insertatend(tail, data);
        return;
    }

    node* newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

//for deleting the node from the list using a given position
void deletenode(node* &head, node* &tail, int pos){
    //deletion at first
    if(pos == 1){
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else{
        // deletion at middle or last node
        node* current = head;
        node* prev = nullptr;
        int cnt = 1;
        while(cnt < pos){
            prev = current;
            current = current->next;
            cnt++;
        }
        prev->next = current->next;
        current->next = nullptr;

        if(prev->next == nullptr){
            tail = prev;
        }
        delete current;
    }
}

//recursive method for reverse of linked list
void reverse(node* &head, node* curr, node* prev){
    if(curr == nullptr){
        head = prev;
        return;
    }

    node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

//reverse the list using recurssion
node* reverselist(node* &head){
    if(head == nullptr || head->next == nullptr){ //if list have no node or only one node
        return head;
    }
    node* prev = nullptr;
    node* current = head;
    reverse(head, current, prev);
    return head;
}

bool checkloop(node* &head){
    if(head == nullptr || head->next == nullptr){
        return false;
    }
    node* fast = head->next;
    node* slow = head;
    while(fast != nullptr && fast->next == nullptr){
        if(slow == fast){
            cout << "\n Loop is found !";
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "\n There is no loop in list !!";
    return false;
}

//printing the list
void printlist(node* &head) {
    node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl; // End of list indicator
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;
    node* node1 = new node(10);

    head = node1;
    tail = node1;

    insertatbeg(head, 5);
    printlist(head);

    insertatend(tail, 15);
    printlist(head);

    insertatend(tail, 20);
    printlist(head);

    insertatposition(head, tail, 1, 30); //position insertion at beg
    insertatposition(head, tail, 3, 40); // insertion at middle
    insertatposition(head, tail, 7, 50);// insertion at end
    printlist(head);


    cout << "\nHead of the list : " << head->data;
    cout << "\nTail of the list : " << tail->data << endl;

    deletenode(head, tail, 7);
    printlist(head);

    cout << "\nHead of the list : " << head->data;
    cout << "\nTail of the list : " << tail->data << endl;

    reverselist(head);
    printlist(head);

    cout << "\nHead of the list : " << head->data;
    cout << "\nTail of the list : " << tail->data << endl;

    checkloop(head);


    
    return 0;
}