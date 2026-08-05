#include<iostream>
using namespace std;
void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
       cout<<"working on pass number "<<i+1<<endl; 
       int isSorted=1;
       for(int j=0;j<n-1-i;j++){
          if(arr[j]>arr[j+1]){ 
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            isSorted=0;}}
       if(isSorted)return;}} 
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<"array element : "<<arr[i]<<endl;}}

int main(){
int arr[]={13,14,12,19,17,11,15,18,20,16};   
int n = sizeof(arr)/sizeof(arr[0]);

printArray(arr,n); 
bubbleSort(arr,n);
printArray(arr,n); 
return 0;}