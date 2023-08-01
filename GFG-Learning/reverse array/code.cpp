#include <iostream>
using namespace std;

void reverseArray(int arr[], int st,int end){
    while(st < end){
        int t = arr[st];
        arr[st] = arr[end];
        arr[end] = t;
        st++;
        end--;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    reverseArray(arr,0,4);
    for(int i=0;i<5;i++) cout << arr[i] << " ";
    return 0;
}