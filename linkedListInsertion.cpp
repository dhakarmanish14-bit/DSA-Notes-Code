#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;};
void insertAtStart(node *&head,int data){
    node *ptr =new node;
        ptr->data=data;
        ptr->next=head;
        head=ptr;}
void insertAtLast(node *head,int data){
    node *ptr =new node;
    //node *temp =head;
    for(int i=0; head->next !=NULL;i++){
        head=head->next;}
        ptr->data=data;
        ptr->next=NULL;
        head->next=ptr;}    
        
void insertAtIndex(node *&head,int data,int index){
     node *ptr =new node;
     node *temp =head;
    for(int i=0;i<index -1 && temp !=nullptr;i++){
        temp=temp->next;}
        ptr->data=data;
        ptr->next=temp->next;
        temp->next=ptr;}
void display(node *head){
while(head !=NULL){
    cout<<"elements :"<<head->data<<"\n";
    head=head->next;}}
int main(){
    node *head =NULL;
    insertAtStart(head,43);
    insertAtStart(head,4);
    insertAtStart(head,13);
    insertAtLast(head,19);
    insertAtStart(head,26);
    display(head);
    insertAtIndex(head,14,3);
    display(head);
    return 0;
}