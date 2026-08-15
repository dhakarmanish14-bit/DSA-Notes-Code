// Count Sort avg case:O(n+k)   worst case:O(n+k)    (use it  when max_elm- min_elm is small)
#include<iostream>
using namespace std;

void countSort(int *arr,int size){
    
    // find the maximum element
    int max_elm=0;
    for(int i=0;i<size;i++) max_elm=max(max_elm,arr[i]);
     
    // store occuring of every element 
    int *new_arr= new int[max_elm+1]();
    for(int i=0;i<size;i++)new_arr[arr[i]]++; 
    
    // transfer back all elements back in arr
    int i=0;int j=0;
    while( i < size ) {
        while (new_arr[j] != 0){ arr[i] = j;new_arr[j]--;i++;}
        j++;
    }
    delete[] new_arr;
}    

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

