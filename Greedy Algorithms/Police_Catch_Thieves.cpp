#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ============ POLICEMAN CATCH THIEVES =================
// =>STATEMENT
// Given an array of size n that has the following specifications:

// 1. Each element in the array contains either a policeman or a thief.
// 2. Each policeman can catch only one thief.
// 3. A policeman cannot catch a thief who is more than K units away from the policeman.
// We need to find the maximum number of thieves that can be caught.

// => EXAMPLE
// Input : arr[] = {'P', 'T', 'T', 'P', 'T'},
//             k = 1.
// Output : 2.
// Here maximum 2 thieves can be caught, first
// policeman catches first thief and second police-
// man can catch either second or third thief.

// Input : arr[] = {'T', 'T', 'P', 'P', 'T', 'P'},
//             k = 2.
// Output : 3.

// Input : arr[] = {'P', 'T', 'P', 'T', 'T', 'P'},
//             k = 3.
// Output : 3.

// => APPROACH
// A brute force approach would be to check all feasible sets of combinations of police and thief and return the maximum size set among them. Its time complexity is exponential and it can be optimized if we observe an important property.
// An efficient solution is to use a greedy algorithm. But which greedy property
// to use can be tricky. We can try using: “For each policeman from the left catch the nearest possible thief.” This works for example three given above but fails for example two as it outputs 2 which is incorrect.
// We may also try: “For each policeman from the left catch the farthest possible thief”. This works for example two given above but fails for example three as it outputs 2 which is incorrect. A symmetric argument can be applied to show that traversing for these from the right side of the array also fails. We can observe that thinking irrespective of the
// policeman and focusing on just the allotment works:
// 1. Get the lowest index of policeman p and thief t. Make an allotment
// if |p-t| <= k and increment to the next p and t found.
// 2. Otherwise increment min(p, t) to the next p or t found.
// 3. Repeat above two steps until next p and t are found.
// 4. Return the number of allotments made.
// Below is the implementation of the above algorithm. It uses vectors to
// store the indices of police and thief in the array and processes them.

int policeThief(char arr[], int n, int k)
{
    int res = 0;
    vector<int> pol, thf;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
            pol.push_back(i);
        else
            thf.push_back(i);
    }

    int l = 0, r = 0;
    while (l < thf.size() and r < pol.size())
    {
        if (abs(thf[l++] - pol[r++]) <= k)
            res++;
        else if (thf[l] < pol[r])
            l++;
        else
            r++;
    }
    return res;
}

int main()
{
    int k, n;
    char arr1[] = {'P', 'T', 'T', 'P', 'T'};
    k = 2;
    n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum thieves caught: " << policeThief(arr1, n, k) << endl;

    char arr2[] = {'T', 'T', 'P', 'P', 'T', 'P'};
    k = 2;
    n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Maximum thieves caught: " << policeThief(arr2, n, k) << endl;

    char arr3[] = {'P', 'T', 'P', 'T', 'T', 'P'};
    k = 3;
    n = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Maximum thieves caught: " << policeThief(arr3, n, k) << endl;
    return 0;
}