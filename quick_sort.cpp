// Quick Sort avg case:O(n log n)   worst case:O(n)²  
#include<iostream>
using namespace std;
int partition(int *arr,int left,int right){
    int pivot=arr[left];
    int i=left+1,j=right;
    while((i<=j)){
          while(i<right&&arr[i]<=pivot)i++;
          while(j>left&&arr[j]>pivot)j--;
          if(i<j)swap(arr[i],arr[j]);}
    swap(arr[left],arr[j]);
    return j;}
void quickSort(int *arr,int left,int right){
     if(left<right){
       int pivotIndex=partition(arr,left,right);
       quickSort(arr,left,pivotIndex-1);
       quickSort(arr,pivotIndex+1,right);}}    

      
void printArray(int arr[],int n){
     for(int i=0;i<n;i++){
     cout<<"array element : "<<arr[i]<<endl;}}

int main(){
int arr[]={13,14,12,19,17,11,15,18,20,16};   
int n = sizeof(arr)/sizeof(arr[0]);

printArray(arr,n); 
quickSort(arr,0,n-1);
printArray(arr,n); 
return 0;}