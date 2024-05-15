#include<iostream>
using namespace std;

void quick(int arr[], int low, int up);
int partition(int arr[], int low, int up);

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int up = n - 1;

    cout << "The unsorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    quick(arr, low, up); 

    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

void quick(int arr[], int low, int up) {
    int pvtloc;
    if (low >= up)
        return;
    pvtloc = partition(arr, low, up);
    quick(arr, low, pvtloc - 1);
    quick(arr, pvtloc + 1, up);
}

int partition(int arr[], int low, int up) {
    int temp, i, j, pivot;
    i = low + 1;
    j = up;
    pivot = arr[low];
    while (i <= j) {
        while ((arr[i] < pivot) && (i < up))
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else {
            i++;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}
//Output
/*
Enter the number of elements in the array: 5
Enter the elements of the array: 55 22 11 4 9
The unsorted array is: 55 22 11 4 9 
The sorted array is: 4 9 11 22 55 
*/
