#include<iostream>
using namespace std;

class bubble{
    public:
    int i,j,k,minindex;

    void sortdata(int arr[] , int size){
        for(i=1;i<size;i++){
            for(j=0;j<size-i;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        for(i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    int array[5]= { 4, 9 , 2 ,5, 3};
    int size=5;
    bubble b;
    b.sortdata(array,size);
}