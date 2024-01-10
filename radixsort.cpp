#include<iostream>
using namespace std;
const int n = 17;
//this function will calculate the max element in the array and return the array. 
int findmax(int arr[] , int N){
    int max = arr[0];
    for(int i=0 ; i < N ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[] , int N , int pos){
    int *arr2;
    int k= 10;
    //creating an array to copy the elements
    arr2 = new int[k];
    for (int i = 0; i < k; i++) {
        arr2[i] = 0;
    }

    //calculating the frequency of the elements
    for(int i=0;i<N;i++){
        arr2[(arr[i]/pos)%10]++;
    }
    for(int i=1 ; i<k ; i++){
        arr2[i] = arr2[i] + arr2[i-1];
    }
    int *arr3;
    arr3 = new int[N];
    for(int i=N-1 ; i>=0 ; i--){
        arr3[--arr2[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<N;i++){
        arr[i] = arr3[i];
    }
}

//calculating the max element in the array. 
void radixsort(int arr[] , int N){
    int max = findmax(arr,N);
    for(int pos=1 ; max/pos >0 ; pos=pos*10){
        countsort(arr,N,pos);
    }
}

int main() {
    int arr[n] = {2,41,44,182,187,31,39,27,44,65,31,22,182,27,65,2,39};

    cout << "Original array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;

    radixsort(arr,n);
    
    cout << "Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;

    return 0;
}
