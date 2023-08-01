// Statement : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461#problem

#include <bits/stdc++.h>
using namespace std;

int getAscii(char c){
    return int(c);
}

int solve(){
    string s,f;
    cin >> s;
    cin >> f;

    int ans = 0;
    int sol = 0;
    if(s == f) return 0;
    for(int i=0;i<s.size();i++){
        ans = INT_MAX;
        for(int j=0;j<f.size();j++){
            char x = s[i];
            char y = f[j];

            if(x > y){
                x = f[j];
                y = s[i];
            }
            int temp = min((int)(y-x), (int)('z'-y+x-'a'+1));
            ans = min(ans, temp); 
            //cout << s1 <<  " " << s2 << " " << cw_count << " " << acw_count << " " << temp << " " << ans << endl;     
        }
       
        sol += ans;
        //cout << sol << endl;
    }
    return sol;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}