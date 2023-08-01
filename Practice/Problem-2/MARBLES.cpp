#include <iostream>
using namespace std;

long long int comb(int n,int r){
        long long int res =1;
        if(r > n/2) r=n-r;
        
        for(int i=0;i<r;i++){
            res *=n;
            res/= i+1;
            n--;
        }
        return res;
}

int main() {
    long long int k;
    int n,c;
    int T;
    cin >>T;
    while(T>0){
        cin >> n >> c;
        
             k = comb(n-1, n-c);
        cout << k << endl;
       
        T--;
    }
    
	// your code goes here
	return 0;
}
