#include<iostream>
using namespace std;
void bin_search(int arr[],int m,int n){int i=0,mid;
  while(i<=n){
      mid=(i+n)/2;
    if(arr[mid]==m){
     cout<<"the entered value is " <<arr[mid]<<" found at index: "<<mid<<endl;
     return;}
    else if(arr[mid]<m){
     i=mid; } 
     
    else{
        n=mid;} }}
int main(){int m;int n;int arr[20];
    cout<<"enter the total number of inputs :"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
     cin>>arr[i]; }
     cout<<"enter the no. for searching :"<<endl;
     cin>>m;
    bin_search(arr,m,n);

    return 0;}