#include <iostream>
using namespace std;

int main() {
    long int N,T,count=0;
    cin >> N >> T;
    int arr[N] = {0};
    while(T--){
        long int F,A,B;
        cin >> F >> A >> B;
        for(int i=A;i<=B;i++){
            if(F==0){
                if(arr[i]==1) arr[i]=0;
                else arr[i]=1;
            }
            if(F==1){
                if(arr[i] == 1) count++;
            }
        }
        if(F==1) cout <<count << endl;
        count =0;
    }
	// your code goes here
	return 0;
}
