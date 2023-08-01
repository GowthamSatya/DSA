#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll sum=0;
    ll N, x,y; 
      cin >> N >> x >> y;
    ll A[N];
    ll B[N];
    
  
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    for(int i=0;i<N;i++){
        cin >> B[i];
    }
    
    for(int i=0;i<N;i++){
        B[i] = B[i] - A[i];
    }
    
    sort(B, B+N);
    
    for(int i=0;i<N;i++){
        if(((y>0) && (B[i] >0)) || (x==0)){
            sum +=A[i] + B[i];
            y--;
        }else{
            sum+= A[i];
            x--;
        }
    }
    
    cout << sum;
    
	// your code goes here
	return 0;
}
