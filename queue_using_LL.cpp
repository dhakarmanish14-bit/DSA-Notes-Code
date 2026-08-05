#include<iostream>
using namespace std;
int count=0;
int maxx=10;
struct node{
int data;
node*next;};
int isempty(node*ptr){
    return ptr==NULL;}
int isfull(node*ptr){
    return count==maxx;}
void enqueue(node*&first,node*&last,int value){
    if(count==maxx){
    cout<<"queue overflow! cannot enqueue element"<<endl;}
    else{
        
    node*ptr=new node;
    ptr->data=value;
    ptr->next=first;
    first=ptr;
    if(last==NULL){last=ptr;}
    count++;}}
int dequeue(node*&first,node*&last){
    if(last==NULL){
    cout<<"queue underflow! cannot dequeue element"<<endl;
    return -1;}
    else{
    node*ptr=last;
    int value=ptr->data;
    node*h=first;
    for(int i=0;h->next->next!=NULL;i++){
    h=h->next;}  
    last=h;
    last->next=NULL;
    if(isempty(first)){first=last=nullptr;}
    count--;
    delete ptr;
    return value;}}
void display(node*ptr){
    while(ptr!=NULL){
    cout<<"element : "<<ptr->data<<endl;
    ptr=ptr->next;}}        

int main(){
    node*first=nullptr;
    node*last=nullptr;
    enqueue(first,last,21);
    enqueue(first,last,22);
    enqueue(first,last,23);
    enqueue(first,last,24);
    enqueue(first,last,25);
    enqueue(first,last,26);
    enqueue(first,last,27);
    display(first);
    dequeue(first,last);
    display(first);
     return 0;}