#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int ans = 0;  
 
    for (int i = 0; i < 32; i++)
    {
        long long int k = 0; 
        for (int j = 0; j < n; j++)
            if ( (a[j] & (1 << i)) )
                k++;
        ans += (1<<i) * (k*(k-1)/2);
    }
    cout<<ans;
    return 0;

}