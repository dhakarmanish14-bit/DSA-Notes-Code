#include<iostream>
using namespace std;
struct node{
int data;
node*left;
node*right;
node(int value){
data=value;
left=right=nullptr;}};

node*search(node*root,int value){
    if(root==NULL)return NULL;
    
    if(value==root->data)return root;
    else if(value<root->data)return search(root->left,value);
    else return search(root->right,value);}

int main(){
node*root=new node(14);
node*l1=root->left=new node(12);
node*r1=root->right=new node(15);
node*l1l2=l1->left=new node(11);
node*l1r1=l1->right=new node(13);

node*n=search(root,11);
if(n!=NULL)cout<<"element found :"<<n->data<<endl;
else cout<<"element not found"<<endl;
return 0;}