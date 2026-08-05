#include<iostream>
using namespace std;
struct node{
      int data;
      node*left;
      node*right;};
node*createNode(int value){
    node*newNode=new node;
    newNode->data=value;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;}   
void preOrderTraversal(node*root){
    if(root!=NULL){
      cout<<root->data<<endl;
      preOrderTraversal(root->left);
      preOrderTraversal(root->right);}}    
void inOrderTraversal(node*root){
    if(root!=NULL){
      inOrderTraversal(root->left);
      cout<<root->data<<endl;
      inOrderTraversal(root->right);}}   
void postOrderTraversal(node*root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);    
        cout<<root->data<<endl;}}
int main(){
    node*root=createNode(11);
    node*l1=createNode(12);
    node*r1=createNode(13);
    node*l1l2=createNode(14);
    node*l1r1=createNode(15);
    root->left=l1;
    root->right=r1;
    l1->left=l1l2;
    l1->right=l1r1;
    
    preOrderTraversal(root);
    inOrderTraversal(root);
    postOrderTraversal(root);
    return 0;}