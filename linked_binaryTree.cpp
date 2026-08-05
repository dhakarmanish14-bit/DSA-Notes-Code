#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;};
node*createNode(int data){
    node* newNode=new node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;}  
int main(){
    node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;
    return 0;}     
