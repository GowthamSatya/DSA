#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T,sum=0;
	cin >> T;
	while(T--){
	    long long int n;
	    cin >> n;
	    long long int arr[n];
	    for(int i=0;i<n;i++) cin >> arr[i];
	    
	    for(int i=0;i<n;i++) sum+= arr[i];
	    
	    int c=0;
	    for(int i=0;i<n;i++) if(arr[i] > 0) c++;
	    long long int lo=sum -c;
	    long long int hi = sum;
	    if(lo <100 && hi>=100) cout << "YES" <<endl;
	    else cout << "NO" << endl;
	    sum=0;
	}
	return 0;
}
