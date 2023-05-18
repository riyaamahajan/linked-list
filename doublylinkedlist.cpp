#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *prev;
    node *next;
    node()
    {
        this->data=0;
        this->prev=NULL;
        this->next=NULL;

    }
    node(int data)
    {
        this->data=data;
        this->prev=this->next=NULL;
    }
    ~node()
    {
        cout<<"node with value"<<this->data<<"deleted \n  ";
    }

};
int getlen(node* head)
{
    int len=0;
    node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
void printnode(node* &head)
    {
        node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        } 
    }
    void insertathead(node* &head,node* &tail,int data ){
    if(head==NULL)
    {
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode= new node(data);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
} 
void insertattail(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode=new node(data);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insertatposition(node* &head,node* &tail,int data,int pos)
{
    if(head==NULL)
    {
        node *newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        if(pos==1){
            insertathead(head,tail,data);
            return;
        }
int len=getlen(head);
        if(pos>len)
        {
            insertattail(head,tail,data);
            return;
            }
        int i=1;
        node* prevnode=head;
        while(i < pos-1){
            prevnode=prevnode->next;
            i++;
        }
       node* curr=prevnode->next;
       node* newnode= new node(data);
       prevnode->next=newnode;
       newnode->prev=prevnode;
       curr->prev=newnode;
       newnode->next=curr;
    }

}   
void deletefrompos(node* &head,node* &tail, int pos)
{
    if(head==NULL)
    {
        cout<<"empty";
        return;
    }
    if(head->next==NULL)
    {
        node* temp=head;
        head = NULL;
        delete temp;
        return;
    }
    if(pos==1)
    {
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
}
int len=getlen(head);
    if(pos>len)
    {
        cout<<"enter a valid number";
    }
    if(pos==len)
    {
  node* temp=tail;
  tail=tail->prev;
  temp->prev=NULL;
  tail->next=NULL;
  delete temp;
  return;
}
int i=1;
node* left=head;
while( i<pos-1)
{
    left=left->next;
    i++;
}
node *curr=left->next;
node *right=curr->next;
left->next=right;
right->prev=left;
curr->next=NULL;
curr->prev=NULL;
delete curr;
}

int main()
{
    node* first= new node(10);
     node* second= new node(20);
      node* third= new node(30);
      node* head=first;
      node *tail=third;
      first->next=second;
      second->prev=first;
      second->next=third;
      third->prev=second;
      printnode(first);
      cout<<endl;
      insertathead(head,tail,100);
      printnode(head);
      cout<<endl;
      insertattail(head,tail,99);
       printnode(head);
      
        cout<<endl;
      insertatposition(head,tail,500,2);
       printnode(head);
        cout<<endl;
      deletefrompos(head,tail,1);
       printnode(head);



}