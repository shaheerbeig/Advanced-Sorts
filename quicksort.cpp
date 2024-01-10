#include<iostream>
using namespace std;

int partition(int arr[] , int s , int e){
    //taking the first element as the pivot.
    int pivot = arr[s];
    int ctr = 0;
    for(int i=s+1 ; i<=e ; i++){
        if(arr[i]<=pivot){
            //counting how many elements are smaller then the pivot element. 
            ctr ++;
        }
    }
    //calculating where the pivot should have been placed.
    int pivotindex = s + ctr;
    //swapping the elemenst at the first position that we considered the pivot pivotindex element.
    swap(arr[pivotindex],arr[s]);

    int i=s;
    int j=e;

    while(i<pivotindex && j>pivotindex){
        while(arr[i] <= pivot){
            //no need to swap as element already less than the pivot value and in correct place
            i++;
        }
        while(arr[j] > pivot){
            //no need to swap as element already less than the pivot value and in correct place
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}

void quicksort(int arr[] , int s , int e){
    //base condition
    if(s >= e){
        return ;
    }
    int p = partition(arr,s,e);
    //for left part
    quicksort(arr,s,p-1);
    //for right part
    quicksort(arr,p+1,e);
}

int main(){
    int arr[8] = {1,21,6,43,5,22,90,12};
    int N=8;
    quicksort(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}