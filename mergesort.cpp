#include<iostream>
using namespace std;

void mergesort(int arr[], int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int *temp1 = new int[len1];
    int *temp2 = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++) {
        temp1[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int j = 0; j < len2; j++) {
        temp2[j] = arr[k];  // Fixed: Copy elements to temp2
        k++;
    }

    int i = 0, j = 0;
    k = start;
    while (i < len1 && j < len2) {
        if (temp1[i] <= temp2[j]) {  // Fixed: Use <= instead of <
            arr[k] = temp1[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k++] = temp1[i++];
    }

    while (j < len2) {
        arr[k++] = temp2[j++];
    }

    delete[] temp1;
    delete[] temp2;
}

void merge(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;
    merge(arr, start, mid);
    merge(arr, mid + 1, end);
    mergesort(arr, start, mid, end);
}

int main() {
    int arr[10] = {74, 22, 90, 23, 122, 45, 32, 65, 33, 63};
    int size = 10;
    merge(arr, 0, size - 1);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
