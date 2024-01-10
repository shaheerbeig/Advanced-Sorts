#include<iostream>
using namespace std;

class insertionsort{
    public:
    void sort(int arr[] , int size){
        int i,j,minindex;
        for(i=1;i<size;i++){
            minindex = arr[i];
            j= i -1;
            while(j >= 0 && minindex < arr[j]){
                arr[j+1]=arr[j];
                j = j-1;
            }
            arr[j+1]=minindex;
        }
        for(i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    int arr[5]={1,8,4,3,9};
    int size=5;
    insertionsort obj;
    obj.sort(arr,size);
}