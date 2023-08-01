// <===== PROBLEM STATEMENT AND EXPLAINATION =====>

// The Fibonacci numbers are the numbers in the following integer sequence.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……

// In mathematical terms the sequence Fn of Fibonacci numbers is defined by the recurrence relation
// F(n) = F(n - 1) + F(n - 2)
// with seed values
// F0 = 0 and F1 = 1.

// <===== CODE =======>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursive approach
int fib(int n){
    if(n == 0 || n==1) return n;
    return fib(n-1)+fib(n-2);
}// => Time Complexity : O(2^n)

// recursive DP approach
int fib(int n,int *arr){
    if(n == 0 || n == 1) return n;
    if(arr[n] != 0) return arr[n];
    else{
        arr[n] = fib(n-1,arr) + fib(n-2,arr);
        return arr[n];
    }
}// => Time Complexity : O(n)


// iterative approach
int NthFibNumber(int n)
{
    int *fib = new int(n+1);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int out = fib[n];
    delete []fib;
    return out;
}// => Time Complexity : O(n)

int main()
{
    int n;
    cout << "Enter Number : ";
    cin >> n;
    int *arr = new int(n+1);
    for(int i=0;i<n;i++) arr[i] = 0;
    cout << n << "th Fibonacci Number is : " << NthFibNumber(n) << endl;
    cout << n << "th Fibonacci Number is : " << fib(n, arr) << endl;
    cout << n << "th Fibonacci Number is : " << fib(n) << endl;
    delete arr;
    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(n)