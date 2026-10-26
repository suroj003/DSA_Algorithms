#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int target) {
    int st = 0;
    int end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return mid;
        }
        else if (arr[mid] < target) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << "Element not found" << endl;
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the element to be searched: ";
    cin >> target;
    BinarySearch(arr, n, target);
    return 0;
}