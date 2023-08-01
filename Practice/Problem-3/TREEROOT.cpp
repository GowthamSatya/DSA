#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int n=0;
        int root= 0;
        cin >> n;
        for(int i=0;i<n;i++){
            int ids, sumIds;
            cin >> ids >> sumIds;
            root += (ids  -sumIds);
        }
        cout << root << endl;
    }
	// your code goes here
	return 0;
}
