#include<iostream>

using namespace std;
int count=0;
const int maxx=20;
struct node{
    int data;
    struct node* next;};
int isempty(node *ptr){
    return ptr ==NULL;}

int isfull(node *ptr){
    return count==maxx;}
void linklistTraversal(node*ptr){
    while(ptr!=nullptr){
        cout<<"element:"<<ptr->data<<endl;
        ptr=ptr->next;}}    
void push(node *&head,int data){
    node *ptr =new node;
    ptr->data=data;
    ptr->next=head;
    head=ptr;
     count++;} 
void pop(node*&head){
    node *ptr;
    ptr=head;
    head =head->next;
    
    delete ptr;
    count--;} 
int peek(node*ptr,int pos){
    for(int i=1;i<pos&&ptr!=nullptr;i++){
    ptr=ptr->next;}
    if(ptr !=nullptr){return ptr->data;}
    else{ return -1;}}  
void display(node *ptr){
    if(isempty(ptr)){
        cout << "Stack is empty!" << endl;
        return;}
    while(ptr!=NULL){
        cout << "Element: " << ptr->data << endl;
        ptr=ptr->next;}}          

int main(){
    node *head =NULL;
    push(head,22);
    push(head,23);
    push(head,24);
    push(head,25);
    push(head,26);
    push(head,27);
    display(head);
    pop(head);
    pop(head);
    display(head);
    return 0;
}