// Insertion Sort avg case:O(n)²   worst case:O(n)² 
#include<iostream>
using namespace std;
void insertionSort(int *arr,int n){
    
    for(int i=1;i<=n-1;i++){
       int j,val=arr[i];
       for(j=i-1;j>=0&&arr[j]>val;j--){
          arr[j+1]=arr[j];}
       arr[j+1]=val;}} 

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<"array element : "<<arr[i]<<endl;}}

int main(){
int arr[]={13,14,12,19,17,11,15,18,20,16};   
int n = sizeof(arr)/sizeof(arr[0]);

printArray(arr,n); 
insertionSort(arr,n);
printArray(arr,n); 
return 0;}