#include<iostream>
using namespace std;

class shell {
    public:
    int i,j,k,gap,temp;

    void sort(int arr[] , int n){
        for(gap = n/2 ; gap > 0 ;gap = gap/2){
            for(i = gap ; i<n ; i++){
                temp = arr[i];
                for(j=i;j>gap && arr[j-gap]  > temp ; j = j - temp){
                    arr[j] = arr[j-gap];
                } 
                arr[j] = temp;
            }
        }
        for(i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }
    }
};


int main(){
    int array[5]= { 4, 9 , 2 ,5, 3};
    int size=5;
    shell s;
    s.sort(array,size);
}