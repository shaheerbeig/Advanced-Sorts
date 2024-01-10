#include<iostream>
using namespace std;

int interpolation(int arr[], int val, int start, int end) {
    if (start <= end && val >= arr[start] && val <= arr[end]) {
        int mid = start + ((end - start) / (arr[end] - arr[start])) * (val - arr[start]);

        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            return interpolation(arr, val, mid + 1, end);
        } else {
            return interpolation(arr, val, start, mid - 1);
        }
    }
    return -1;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index = interpolation(arr, 3, 0, 4);
    cout << "Index is: " << index << endl;

    return 0;
}
