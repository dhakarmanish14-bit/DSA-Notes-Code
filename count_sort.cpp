#include<iostream>
using namespace std;
void countSort(int *arr,int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
       if(arr[i]>max)max=arr[i];}
    int *count=new int[max+1]();
    for(int i=0;i<n;i++){
        count[arr[i]]++;}
    int index=0;
    for(int i=0;i<=max;i++){
        while(count[i]>0){
            arr[index++]=i;
            count[i]--;}}
    delete[] count;} 
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<"array element : "<<arr[i]<<endl;}}

int main(){
int arr[]={13,14,12,19,17,11,15,18,20,16};   
int n = sizeof(arr)/sizeof(arr[0]);

printArray(arr,n); 
countSort(arr,n);
printArray(arr,n); 
return 0;}