#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;};

void linkedListTraversal(struct node *head){
    node*ptr=head;
    do{cout << "Elements: " << ptr->data << endl;
    ptr = ptr->next;}while (ptr!=head);}

int main() {            
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Memory allocation
   head = new node;
   second = new node;
   third = new node;
   fourth = new node;

    // Assign data and link
    head->data = 7;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 35;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = head;

    // Traverse
    linkedListTraversal(head);

    delete head;
    delete second;
    delete third;
    delete fourth;
    return 0;
}