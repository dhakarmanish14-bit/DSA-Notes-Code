#include<iostream>
using namespace std;
struct node{
int data;
int height;
node*left;
node* right;};

node*createNode(int value){
    node*newNode=new node;
    newNode->data=value;
    newNode->height=0;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;}   

void preOrderTraversal(node*root){
    if(root!=NULL){
      cout<<root->data<<endl;
      preOrderTraversal(root->left);
      preOrderTraversal(root->right);}}

int getHeight(node*root){
    if(root==NULL)return -1;
    return root->height;}

int getBalanceFactor(node*root){
    if(root==NULL)return 0;
    return getHeight(root->left)-getHeight(root->right);}

node*rightRotate(node*z){
    node*x=z->left;
    node*y=x->right;
    x->right=z;
    z->left=y;
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return x;}

node*leftRotate(node*x){
    node*z=x->right;
    node*y=z->left;
    z->left=x;
    x->right=y;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    return z;} 
        
node* insert(node*ptr,int value){
    if(ptr==nullptr){ 
    return createNode(value);}
    else if(value<ptr->data){
    ptr->left=insert(ptr->left,value);}
    else{ptr->right=insert(ptr->right,value);}
    
    ptr->height=max(getHeight(ptr->left),getHeight(ptr->right))+1;
    int bf=getBalanceFactor(ptr);

    //left left case
    if(bf>1&&ptr->left->data>value){
        return rightRotate(ptr);}
    //right right case    
    if(bf<-1&&ptr->right->data<value){
        return leftRotate(ptr);}
    //left right case
    if(bf>1&&ptr->left->data<value){
        ptr->left=leftRotate(ptr->left);
        return rightRotate(ptr);}
    //right left case
    if(bf<-1&&ptr->right->data>value){
        ptr->right=rightRotate(ptr->right);
        return leftRotate(ptr);}    
    
    return ptr;}

int main(){
    node*root=nullptr;

    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    preOrderTraversal(root);
    return 0;}    