#include <iostream>
using namespace std;

struct stack {
    int maxx;
    int top;
    int *arr;
};

int isempty(stack *ptr){
    return (ptr->top == -1);
}

int isfull(stack *ptr){
    return (ptr->top == ptr->maxx - 1);
}

void push(stack *ptr, int value){
    if(isfull(ptr)){
        cout << "Stack overflow, can't push." << endl;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(stack *ptr){
    if(isempty(ptr)){
        cout << "Stack empty, cannot pop." << endl;
        return -1;
    } else {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(stack *ptr){
    if(isempty(ptr)){
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return ptr->arr[ptr->top];
}

void display(stack *ptr){
    if(isempty(ptr)){
        cout << "Stack is empty!" << endl;
        return;
    }
    for(int i = 0; i <= ptr->top; i++){
        cout << "Element: " << ptr->arr[i] << endl;
    }
}

int main(){
    stack *a1 = new stack;   // allocate memory for stack struct
    a1->maxx = 20;
    a1->top = -1;
    a1->arr = new int[a1->maxx];   // allocate array of integers

    push(a1, 23);
    push(a1, 24);
    push(a1, 25);

    cout << "Top element = " << peek(a1) << endl;

    display(a1);

    cout << "Popped = " << pop(a1) << endl;

    display(a1);

    return 0;}