#include<iostream>
using namespace std;
struct node{
int data;
node*left;
node*right;
node(int value){
data=value;
left=right=nullptr;}};

void insert(node*root,int value){
    node*parent=NULL;
    while(root!=NULL){
        parent =root;
         if(value==root->data){
            cout<<"cannot insert element:"<<value<<" as already present in BST"<<endl;
            return;}
         else if(value <root->data){
                 root= root->left;} 
         else{root=root->right;}}
    node*ptr=new node(value);
    if(value<parent->data)parent->left=ptr;
    else parent->right=ptr;} 

node*search(node*root,int value){
    if(root==NULL)return NULL;
    if(value==root->data)return root;
    else if(value<root->data)return search(root->left,value);
    else return search(root->right,value);}
    
int main(){
node*root=new node(14);
node*l1=root->left=new node(12);
node*r1=root->right=new node(15);
node*l1l2=l1->left=new node(10);
node*l1r1=l1->right=new node(13);

insert(root,17);
node*n=search(root,17);
if(n!=NULL)cout<<"element found :"<<n->data<<endl;
else cout<<"element not found"<<endl;

insert(root,11);
n=search(root,11);
if(n!=NULL)cout<<"element found :"<<n->data<<endl;
else cout<<"element not found"<<endl;

insert(root,12);
n=search(root,12);
if(n!=NULL)cout<<"element found :"<<n->data<<endl;
else cout<<"element not found"<<endl;

return 0;}