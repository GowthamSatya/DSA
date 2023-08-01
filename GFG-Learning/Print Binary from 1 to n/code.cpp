#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printBinary(int n){
    queue<string> q;

    q.push("1");
    for(int i=1;i<=n;++i){
        string c = q.front();
        q.pop();
        cout << c<< '\n';
        q.push(c+"0");
        q.push(c+"1");
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    printBinary(10);
}