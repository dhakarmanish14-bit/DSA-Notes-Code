#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    // 1️⃣ std::sort - ascending
    sort(arr1, arr1 + n);
    cout << "After sort: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    // 2️⃣ std::stable_sort - stable sorting
    int arr2[] = {3, 1, 4, 1, 5};
    stable_sort(arr2, arr2 + 5);
    cout << "After stable_sort: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    // 3️⃣ std::partial_sort - sort first 3 smallest
    int arr3[] = {9, 3, 7, 1, 5, 2};
    partial_sort(arr3, arr3 + 3, arr3 + 6);
    cout << "After partial_sort (3 smallest first): ";
    for (int x : arr3) cout << x << " ";
    cout << endl;

    // 4️⃣ std::nth_element - place 3rd smallest correctly
    int arr4[] = {8, 2, 5, 1, 7, 4};
    nth_element(arr4, arr4 + 2, arr4 + 6);
    cout << "3rd smallest element: " << arr4[2] << endl;

    // 5️⃣ std::is_sorted & std::is_sorted_until
    int arr5[] = {1, 2, 3, 5, 4};
    cout << boolalpha;
    cout << "Is arr5 sorted? " << is_sorted(arr5, arr5 + 5) << endl;

    auto it = is_sorted_until(arr5, arr5 + 5);
    cout << "Sorted until element: " << *(it - 1) << endl;

    return 0;
}
