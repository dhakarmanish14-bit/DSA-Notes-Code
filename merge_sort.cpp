// Merge Sort avg case:O(n log n)   worst case:O(n log n)  (use it  when max_elm- min_elm is large)

#include<iostream>
using namespace std;

void merge_2sorted_array(int *arr, int start_index, int mid_index, int stop_index) {

    int new_arr[stop_index - start_index + 1];
    int i = start_index; int j = mid_index + 1;

    for (int k = 0; k < stop_index - (start_index-1); k++) {

        // 1. Left half is exhausted
        if (i > mid_index) { new_arr[k] = arr[j];j++;}

        // 2. Right half is exhausted
        else if (j > stop_index) {new_arr[k] = arr[i];i++;}

        // 3. Both halves still have elements → compare
        else if (arr[i] <= arr[j]) {new_arr[k] = arr[i];i++;}
        else { new_arr[k] = arr[j]; j++;}
    }

    // Copy merged array back into original array
    for (int k = 0; k < stop_index - start_index + 1; k++) {
        arr[start_index + k] = new_arr[k];
    }
    delete[] new_arr;
}


void mergeSort(int*arr,int start_index, int stop_index){
    // base case 
    if(start_index==stop_index)return;

    int mid_index= (start_index+stop_index)/2;

    mergeSort(arr,start_index,mid_index);
    mergeSort(arr,mid_index+1,stop_index);

    merge_2sorted_array(arr,start_index,mid_index,stop_index);
}

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