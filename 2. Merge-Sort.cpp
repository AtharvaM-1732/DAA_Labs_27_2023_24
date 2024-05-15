#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int merged[], int size1, int size2);

int main() {
    int size1, size2;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter elements of the first array:\n";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter elements of the second array:\n";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int merged[size1 + size2];
    merge(arr1, arr2, merged, size1, size2);

    cout << "\nThe merged and sorted array is:\n";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}

void merge(int arr1[], int arr2[], int merged[], int size1, int size2) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    // Sort the merged array
    for (int m = 0; m < size1 + size2 - 1; m++) {
        for (int n = 0; n < size1 + size2 - m - 1; n++) {
            if (merged[n] > merged[n + 1]) {
                int temp = merged[n];
                merged[n] = merged[n + 1];
                merged[n + 1] = temp;
            }
        }
    }
}
//Output
/*
Enter the size of the first array: 2
Enter elements of the first array:
22 42
Enter the size of the second array: 3
Enter elements of the second array:
44 12 18 1

The merged and sorted array is:
12 18 22 42 44
*/
