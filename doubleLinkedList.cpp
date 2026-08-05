#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* previous;};

void linkedListTraversal(struct node *head) {
    while (head->next!= NULL) {
        cout << "Elements: " << head->data << endl;
        head = head->next;}
          cout << "Elements: " << head->data << endl;
    do{cout << "Elements: " << head->data << endl;
        head = head->previous; }while(head !=NULL);}

int main() {            
    struct node *head=new node;
    struct node *second=new node;
    struct node *third=new node;
    struct node *fourth=new node;

    head->data = 7;
    head->previous=NULL;
    head->next = second;

    second->data = 3;
    second->previous=head;
    second->next = third;

    third->data = 35;
    third->previous=second;
    third->next = fourth;

    fourth->data = 9;   
    fourth->previous=third;
    fourth->next = NULL;
    linkedListTraversal(head);
    delete head;
    delete second;
    delete third;
    delete fourth;
    return 0;}