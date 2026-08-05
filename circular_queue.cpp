#include<iostream>
using namespace std;

struct queue{
    int size;
    int first;
    int last;
    int *arr;
};

int isempty(queue *ptr){
    return ptr->first == -1;  // or ptr->last == -1 works too
}

int isfull(queue *ptr){
    return (ptr->last+1)%ptr->size == ptr->first;
}

void enqueue(queue *ptr,int value){
    if(isfull(ptr)){
        cout<<"Queue overflow! Cannot enqueue element."<<endl;
    } else {
        if(ptr->first == -1) ptr->first = 0;
        ptr->last = (ptr->last + 1) % ptr->size;
        ptr->arr[ptr->last] = value;
    }
}

int dequeue(queue *ptr){
    if(isempty(ptr)){
        cout<<"Queue underflow! Cannot dequeue element."<<endl;
        return -1;
    } else {
        int value = ptr->arr[ptr->first];
        if(ptr->first == ptr->last)
            ptr->first = ptr->last = -1;
        else
            ptr->first = (ptr->first + 1) % ptr->size;
        return value;
    }
}

void display(queue *ptr){
    if(isempty(ptr)){
        cout<<"Queue is empty."<<endl;
        return;
    }
    for(int i=ptr->first; i!=ptr->last; i=(i+1)%ptr->size){
        cout<<"element : "<<ptr->arr[i]<<endl;
    }
    cout<<"element : "<<ptr->arr[ptr->last]<<endl;  // ✅ fixed
}

int main(){
    queue q1;
    q1.size = 10;
    q1.first = q1.last = -1;
    q1.arr = new int[q1.size];

    enqueue(&q1,10);
    enqueue(&q1,20);
    enqueue(&q1,30);
    enqueue(&q1,40);
    enqueue(&q1,50);
    enqueue(&q1,60);
    enqueue(&q1,70);
    enqueue(&q1,80);
    enqueue(&q1,90);
    enqueue(&q1,100);

    display(&q1);

    cout<<"The "<<dequeue(&q1)<<" got removed"<<endl;

    enqueue(&q1,110);

    display(&q1);

    return 0;
}