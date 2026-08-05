#include <iostream>
#include <list>
using namespace std;

int main() {
    // create a doubly linked list
    list<int> myList;

    // Insert elements
    myList.push_back(10);   // add at end → [10]
    myList.push_front(20);  // add at front → [20, 10]
    myList.push_back(30);   // → [20, 10, 30]

    cout << "Initial list: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // Access first and last element
    cout << "First element: " << myList.front() << endl;
    cout << "Last element: " << myList.back() << endl;

    // Size and empty check
    cout << "List size: " << myList.size() << endl;
    cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << endl;

    // Insert at specific position (2nd position)
    auto it = myList.begin();
    ++it; // move to 2nd element
    myList.insert(it, 25); // → [20, 25, 10, 30]

    cout << "After insert: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // Erase 2nd element
    it = myList.begin();
    ++it;
    myList.erase(it); // removes 25 → [20, 10, 30]

    cout << "After erase: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // Remove all occurrences of 10
    myList.remove(10); // → [20, 30]

    cout << "After remove(10): ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // Add more elements for sorting
    myList.push_back(5);
    myList.push_back(40);

    cout << "Before sort: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    myList.sort(); // sorts in ascending order → [5, 20, 30, 40]

    cout << "After sort: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    myList.reverse(); // → [40, 30, 20, 5]

    cout << "After reverse: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // Pop operations
    myList.pop_front(); // removes first → [30, 20, 5]
    myList.pop_back();  // removes last → [30, 20]

    cout << "After pop operations: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // Clear the list
    myList.clear();

    cout << "After clear, is empty? " 
         << (myList.empty() ? "Yes" : "No") << endl;

    return 0;
}