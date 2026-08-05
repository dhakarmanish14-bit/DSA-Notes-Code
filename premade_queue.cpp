#include <iostream>
#include <queue>  // include the queue library
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Adding (enqueue) elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Elements have been added to the queue.\n\n";

    // Display front and back elements
    cout << "Front element: " << q.front() << endl;  // First element
    cout << "Back element: " << q.back() << endl;    // Last element
    cout << "Queue size: " << q.size() << endl;

    cout << "\nRemoving elements one by one:\n";

    // Removing (dequeue) elements
    while (!q.empty()) {
        cout << "Front: " << q.front() << "  --> removing it\n";
        q.pop();
    }

    // After emptying the queue
    cout << "\nIs the queue empty now? " 
         << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
