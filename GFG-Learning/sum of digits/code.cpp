#include <iostream>
using namespace std;

int getSum(int n){
    int sum=0;
    while(n>0){
        int ld = n%10;
        sum += ld;
        n/=10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int s = getSum(n);
    cout << s <<endl;
    return 0;
}