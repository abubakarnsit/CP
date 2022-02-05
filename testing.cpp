#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    n->prev = NULL;
    // if(head!=NULL){
    //     head->prev = n;
    // }
    head = n;

}


void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;

}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

// Delete  start from Double Linked-List
void deleteAtHead(node* &head){
    if(head==NULL){
        return;
    }
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

// Delete At Middle

void deletion(node* &head, int pos){
    int count=1;
    node* temp = head;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    while(temp!=NULL and count!=pos){
        cout<<count<<" "<<temp->data<<endl;
        temp=temp->next;
        count++;
        //cout<<count<<" "<<temp->data<<endl;
    }
    cout<<count<<" "<<temp->data<<endl;
    cout<<"abb"<<endl;
    temp->prev->next = temp->next;
    cout<<"abc"<<endl;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    cout<<"abs"<<endl;
    delete temp;
}


int main(){
    node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,1);
    insertAtHead(head,8);
    insertAtTail(head,4);
    insertAtHead(head,9);
    deleteAtHead(head);
    cout<<"A"<<endl;
    display(head);
    cout<<"C"<<endl;
    deletion(head,3);
    cout<<"B"<<endl;
    display(head);
    return 0;
}