#include<iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size =0;
    heap(){
    arr[0]=0;
    size=0;}

void insert(int val){
      size = size +1;
     int  index = size;
     arr[index] = val;

     while(index >1){
        int parent = index/2;
    if(arr[parent]>arr[index]){
          swap(arr[parent],arr[index]);
          index=parent;
     }
     else{   return;}}}

void delete_elm(){
    if(size==0){
        cout<<"nothing to delete"<<endl;
        return;
    }
    arr[1]=arr[size];
    size--;
    int index =1;
    while(index< size){
        int leftIndex = 2*index;
        int rightIndex = 2*index +1;

        if(leftIndex<=size && arr[index]>arr[leftIndex] && (rightIndex > size || arr[leftIndex] < arr[rightIndex])){
            swap(arr[index],arr[leftIndex]);
            index =leftIndex;   
        }

        else if(rightIndex<=size && arr[index]>arr[rightIndex] && arr[leftIndex] > arr[rightIndex]){
            swap(arr[index],arr[rightIndex]);
            index =rightIndex;   
        }
        else{ return; }
    }
}



void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";}
    cout<< endl;    
    }

};

void heapify(int arr[],int index,int size) {

    int smallest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= size && arr[left] < arr[smallest])
        smallest = left;

    if (right <= size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapify(arr, size, smallest);
    }
}

// descending order
void heapSort(int arr[],int last){ 
    if(last==1) return; 
    swap(arr[1],arr[last]); 
    last--; 
    heapify(arr,last,1);
    heapSort(arr,last); }


int main(){

    heap h;
    h.insert(20);
    h.insert(10);
    h.insert(50);
    h.insert(30);

    h.print();

    h.insert(60);
    h.insert(40);
    h.insert(80);
    h.insert(70);
    h.insert(90);

    h.print();
    
    h.delete_elm();

    h.print();
    
    int arr[6]={0,30,60,40,80,70};
     int n=5;
    for(int i= n/2;i>0;i--){
        heapify(arr,n, i);
    }

    heapSort(arr,n);
    
    for(int i =1;i<=n;i++){
        cout<<arr[i]<<" "<<endl;
    }

    return 0;
}