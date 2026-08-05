#include<iostream>
#include<climits>
using namespace std;
struct node{
int data;
node*left;
node*right;
node(int value){
data=value;
left=right=nullptr;}};

int isBST(node*root,int minVal,int maxVal){
    if(root==nullptr)return 1;
    if(root->data<=minVal||root->data>=maxVal)return 0;
    return isBST(root->left,minVal,root->data)&&isBST(root->right,root->data,maxVal);
}
int main(){
node*root=new node(11);
node*l1=root->left=new node(12);
node*r1=root->right=new node(13);
node*l1l2=l1->left=new node(14);
node*l1r1=l1->right=new node(15);
if(isBST(root,INT_MIN,INT_MAX))
   cout<<"tree is a BST \n"<<endl;
else
   cout<<"tree is not a BST \n"<<endl;
return 0;}