#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* next;};

void linkedListTraversal( node *head) {
    while (head != NULL) {
        cout << "Elements: " << head->data << endl;
        head = head->next;}}
void deleteLast(node*head){
    node*h=head;
    for(int i=0;h->next->next!=NULL;i++){
        h=h->next;}
    node*ptr=h->next;   
    h->next=NULL;
    delete ptr;}
void deleteFirst(node*&head){
    node *ptr;
    ptr=head;
    head =head->next;
    delete ptr;}

void deleteAtIndex(node*head,int index){
    node*ptr;
    for(int i=0;i<index-1 && head->next!=NULL ;i++){
      head=head->next;}
      ptr= head->next;  
      head->next=ptr->next;
      delete ptr;   }        

int main() {            
     node *head =new node;
     node *second =new node;
     node *third =new node;
     node *fourth =new node;

    head->data = 7;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 35;
    third->next = fourth;
    fourth->data = 9;
    fourth->next = NULL;

    linkedListTraversal(head);
    //deleteAtIndex(head,2);
    //deleteLast(head);
    //deleteFirst(head);
    linkedListTraversal(head);
    return 0;}