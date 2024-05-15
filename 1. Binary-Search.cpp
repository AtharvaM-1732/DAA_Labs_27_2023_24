#include<iostream>
using namespace std;
int main() {
    int i, n;
    int a[9]; // Declaring an integer array 'a' of size 9
    cout << "Enter the elements in array :" << endl;
    for (i = 0; i < 9; i++) {
        cin >> a[i]; // Taking input for each element of the array from the user
    }
    // Binary Search Logic
    int low = 0;
    int high = 9 - 1;
    int mid, found = 0;
    cout << "Enter the element to be searched:";
    cin >> n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == n) {
            cout << "Element found at index " << mid << "!";
            found = 1;
            break;
        }
        else if (a[mid] < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        cout << "\nElement not found!";
    return 0; // Indicating successful completion of the program
}

// Output
/*
Enter 9 elements in array :
8 4 9 2 7 3 2 11 54
Enter the element to be searched:11
Element found at index 7!
*/
