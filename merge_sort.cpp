// Merge Sort avg case:O(n log n)   worst case:O(n log n)  (use it  when max_elm- min_elm is large)
#include<iostream>
using namespace std;
void merge(int*arr,int left,int mid,int right){
int n1=mid+1-left;
int n2=right-mid;
int L[n1],R[n2];
for(int i=0;i<n1;i++){
    L[i]=arr[left+i];}
for(int j=0;j<n2;j++){   
    R[j]=arr[mid+1+j];}
    
int i=0,j=0,k=left;
while(i<n1&&j<n2){
    if(L[i]<=R[j]){arr[k]=L[i];i++;}
    else{arr[k]=R[j];j++;}
    k++;}
    while(i<n1)arr[k++]=L[i++];
    while(j<n2)arr[k++]=R[j++];}
void mergeSort(int arr[],int left,int right){
    if(left<right){
      int mid=(left+right)/2;
      mergeSort(arr,left,mid);
      mergeSort(arr,mid+1,right);
      merge(arr,left,mid,right);}}    
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
    cout<<"array element : "<<arr[i]<<endl;}}
int main(){
int arr[]={13,14,12,19,17,11,15,18,20,16};   
int n = sizeof(arr)/sizeof(arr[0]);

printArray(arr,n); 
mergeSort(arr,0,n-1);
printArray(arr,n); 
return 0;
} 