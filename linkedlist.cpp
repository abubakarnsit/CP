#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(int data)
    {

        this->data=data;
        next=NULL;

    }

};

void insertathead(node *&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return ;
    }
    node*n=new node(data);
    n->next=head;
    head=n;
}

void insertatmiddle(node* &head, int pos,int key)
{
  if(pos==0)
  {
      insertathead(head,key);
  }
  else{
      node*temp=head;
      while(pos!=1)
      {
          temp=temp->next;
          pos--;
      }
      node*n=new node(key);
      n->next=temp->next;
      temp->next=n;
  }
}
void printlist(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* reversethelist(node*&head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }
    node*shead=reversethelist(head->next);
    head->next->next=head;
    head->next=NULL;
    return shead;
}

void reversebyiteration(node*&head)
{
    if(head==NULL or head->next==NULL)
    return ;
    node*prev=NULL;
    node*current=head;
    node* nex;
    while(current!=NULL)
    {
        nex=current->next;
        current->next=prev;
        prev=current;
        current=nex;
    }
    head=prev;
    return;
}
void 
node* reversek(node*head,int k)
{
    if(head==NULL or head->next==NULL)
    return head;
    node*prev=NULL;
    node*curr=head;
    node*nex;
    int cnt=1;
    while(curr!=NULL and cnt<=k)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        cnt++;
    }
    if(nex!=NULL)
    {
        head->next=reversek(nex,k);
    }
    return prev;

}
node*mergetwo(node*a,node*b)
{
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    node*c;
    if(a->data<b->data)
    {
        c=a;
        c->next=mergetwo(a->next,b);
    }
    else{
        c=b;
        c->next=mergetwo(a,b->next);
    }
    return c;
}

node*midpoint(node*head)
{
    node*fast=head->next;
    node*slow=head;
    while(fast!=NULL or fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}
node* mergesort(node*head)
{
    if(head==NULL or head->next==NULL)
    return head;
    node*mid=midpoint(head);
    node*a=head;
    node*b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);
    return mergetwo(a,b);
}
int main()
{
    node*head=NULL;
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,0);
    insertathead(head,-1);
    insertathead(head,10);
    insertathead(head,9);
    insertathead(head,-5);

    printlist(head);
    insertatmiddle(head,3,10);
    printlist(head);
    head=reversethelist(head);
    printlist(head);
    reversebyiteration(head);
    printlist(head);
    head=reversek(head,3);
    printlist(head);
    head=mergesort(head);
    printlist(head);

}