#include<iostream>
using namespace std;

int binary(int arr[] , int size , int val){
    int start=0;
    int end = size-1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(arr[mid] == val){
            return mid;
        }
        else if(val > arr[mid]){
            start = mid +1;
        }   
        else if(val < arr[mid]){
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int N,key;
    int index = binary(arr,5,4);
    cout<<"index is:"<<index;
}