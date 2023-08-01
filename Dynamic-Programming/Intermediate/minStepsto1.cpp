#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minSteps(int n){
    // base case 
    if(n == 1) return 0;

    // recursive case
    int x = minSteps(n-1);
    int y= INT_MAX,z= INT_MAX;
    if(n%2==0){
        y = minSteps(n/2);
    }
    if(n%3==0){
        z = minSteps(n/3);
    }

    // ans 
    int sol = min(min(x,y), z)+1;
    return sol;
} // 2^n time complexity


// DP solution - top-down approach
// only 'n' unique function calls will happen
// Time complexity is O(n)
int minSteps_td(int n){

}

int main(){
    cout << minSteps(7) << endl;
    return 0;
}