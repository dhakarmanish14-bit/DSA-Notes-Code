#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // push
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  // 30

    // pop
    s.pop(); // removes 30
    cout << "Top after pop: " << s.top() << endl; // 20

    // size
    cout << "Stack size: " << s.size() << endl;  // 2

    // empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // swap
    stack<int> s2;
    s2.push(100);
    s2.push(200);

    s.swap(s2); //interchanges two different stack content
    cout << "Top after swap: " << s.top() << endl; // 200

    return 0;
}