// Selection Sort avg case:O(n)²   worst case:O(n) 
#include<iostream>
using namespace std;
void selectionSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
       int leastIndexValue=i;
       for(int j=i+1;j<=n-1;j++){
          if(arr[leastIndexValue]>arr[j]){
            leastIndexValue=j;}}
       int temp= arr[i];
           arr[i]=arr[leastIndexValue];
           arr[leastIndexValue]=temp;}} 
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<"array element : "<<arr[i]<<endl;}}

int main(){
int arr[]={13,14,12,19,17,11,15,18,20,16};   
int n = sizeof(arr)/sizeof(arr[0]);

printArray(arr,n); 
selectionSort(arr,n);
printArray(arr,n); 
return 0;}