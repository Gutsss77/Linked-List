#include<iostream>
using namespace std;

//strucure of node
class node{

    public:
    int data;
    node* next;

    node(int data) { //constructor
        this->data = data;
        this->next = nullptr;
    }
};

//insertion at head
void insertathead(node* &head, int data){
    node* temp = new node(data);
    if(head == nullptr){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

//insertion at tail
void insertattail(node* &tail, int data){
    node* temp = new node(data);
    if(tail == nullptr){
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

/* node* reverse1(node* &head){
    //base case
    if(head == nullptr || head->next == nullptr){
        return head;
    }
}
node* reversell(node* &head){
    return reverse1(head);
} */

//reversing the list
node* reverselist(node* &head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    node* current = head;
    node* prev = nullptr;
    node* forward = nullptr;

    while(current != nullptr){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
    return head;
} 

//finding the length of the list
int getlengthoflist(node* &head){
    int len=0;
    node* current = head;
    while(current != nullptr){
        len++;
        current = current->next;
    }
    return len;
}

//finding the greatest element in list
int greatestelementinlist(node* head) {
    if (head == nullptr) {
        throw std::invalid_argument("List is empty");
    }

    node* current = head;
    int max = current->data;  // Initialize max with the first element's data

    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

//finding the middle element approach1
int midelementinlist(node* &head, int len){
    int mid;
    mid = len/2;

    node* current = head;
    int i = 0;
    while(i < mid){

        current = current->next;
        i++;
    }
    return current->data;
}

//finding the middle element using approach2
int getmid(node* &head){

    if(head == nullptr || head->next == nullptr){
        return 0;
    }
    if(head->next->next == nullptr){
        return head->next->data;
    }

    node* fast = head->next;
    node* slow = head;
    while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data;
}

//printing the list
void printlist(node* &head){
    node* current = head;
    cout << "\n";
    while(current != nullptr){
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL";
}

int main(){
    node* head = nullptr;
    node* tail = nullptr;

    insertathead(head, 30); //insert at head
    tail = head;
    insertathead(head, 25);
    insertathead(head, 20);
    insertathead(head, 15);
    insertathead(head, 10);

    insertattail(tail, 35); //insert at tail
    insertattail(tail, 40);
    cout << "\nCurrent list is : ";
    printlist(head);

    int x = greatestelementinlist(head);
    cout << "\nMaximum element is : " << x;

    int l = getlengthoflist(head);
    cout << "\nlength element is : " << l;

    int m = midelementinlist(head, l);
    cout << "\nMiddle element is : "<< m;

    cout << "\nMiddle element from approach 2 : " << getmid(head);

    cout << "\nCurrent head : " << head->data;
    cout << "\nCurrent tail : " << tail->data;

    reverselist(head);
    cout << "\nThe reverse of the list is : ";
    printlist(head);

    return 0;
}