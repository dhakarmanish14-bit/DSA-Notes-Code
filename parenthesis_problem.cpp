#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    char *arr;};
int isEmpty(stack*ptr){
    if(ptr->top==-1){
        return 1;}
    else{ return 0;}}    
int isFull(stack*ptr){
    if(ptr->top==ptr->size-1){
        return 1;}
    else{ return 0;}} 
void push(stack *ptr,char value){
    if(isFull(ptr)){
    cout<<"stack overflow! cannot push element "<<value<<endl;}
    else{ptr->top++;
    ptr->arr[ptr->top]=value;}}
void pop(stack *ptr){
    if(isEmpty(ptr)){
    cout<<"stack empty! cannot pop element "<<endl;}
    else{char value=ptr->arr[ptr->top];ptr->top--;}}    
void eqn_check(string str,stack *ptr){
    int i=0;
    while(str[i] !='\0' ){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){   
        push(ptr,char(str[i])); }
        if(char(str[i]) == *(ptr->arr)){
        pop(ptr);} i++; }
    if(ptr->top==-1){
        cout<<"equation is balanced"<<endl;}
    else{cout<<"equation is unbalanced"<<endl;}}    
int main(){
    stack *a1=new stack;
    a1->size=100;
    a1->top=-1;
    a1->arr=new char;
     string str;
    cout<<"enter equation :"<<endl;
    cin>>str;
    eqn_check(str,a1);
    return 0;}    
