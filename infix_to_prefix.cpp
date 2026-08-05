#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    int *arr;};
int isEmpty(stack*ptr){
    if(ptr->top==-1){
        return 1;}
    else{ return 0;}}    
int isFull(stack*ptr){
    if(ptr->top==ptr->size-1){
        return 1;}
    else{ return 0;}} 
void push(stack *ptr,int value){
    if(isFull(ptr)){
    cout<<"stack overflow! cannot push element "<<value<<endl;}
    else{ptr->top++;
    ptr->arr[ptr->top]=value;}}
int pop(stack *ptr){
    if(isEmpty(ptr)){
    cout<<"stack empty! cannot pop element "<<endl;
    return -1;}
    else{int value=ptr->arr[ptr->top];
    ptr->top--;
    return value;}}      
void inf_pref(stack*ptr,string eqn1){
    string eqn2;
for(int i=0;i<'\0';i++){
if(eqn1[i]=='+'||'-'||'*'||'/'){
push(ptr,eqn1[i]);}
else{eqn2=eqn1[i];}   
if(ptr->arr[ptr->top]=='+'||'-'&&eqn1[i]=='*'||'/'||'+'||'-'){
   push(ptr,eqn1[i]); }
else if(ptr->arr[ptr->top]=='*'||'/'&&eqn1[i]=='+'||'-'){
   while(ptr->top!=-1){eqn2=pop(ptr);} 
    push(ptr,eqn1[i]); }}
   cout<<"the prefix equation of the given infix equation is "<<eqn2<<endl;}
int main(){
struct stack* a1;
a1->size=10;
a1->top=-1;
a1->arr = new int;
string eqn;
cout<<"enter the infix equation"<<endl;
getline(cin,eqn);

    return 0;
}