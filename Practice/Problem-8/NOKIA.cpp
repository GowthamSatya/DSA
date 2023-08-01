#include <iostream>
using namespace std;

int Max(int n){
	    if(n==1) return 2;
	    if(n==2) return 5;
	    
	    return n+1+Max(n-1);
	}
	
	int Min(int n){
	    if(n==1) return 2;
	    if(n==2) return 5;
	    
	    return n+1+Min((n-1)/2)+Min((n-1)-(n-1)/2);
	}

int main() {
	// your code goes here
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    int max = Max(n);
	    int min=Min(n);
	    
	    if(m>=max) cout<<m-max<<endl;
	    else if(m>=min) cout<<0<<endl;
	    else cout<<-1<<endl;
	}
	return 0;
}