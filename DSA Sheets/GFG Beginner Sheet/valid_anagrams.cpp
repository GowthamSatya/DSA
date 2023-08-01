#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/anagram-1587115620/1?page=1&curated[]=8&sortBy=submissions

    Input :
    a = geeksforgeeks, b = forgeeksgeeks

    Output: YES

    Explaination:
    Both the string have same characters with
    same frequency. So, both are anagrams.
*/

bool isAnagram(string a, string b)
{

    // Your code here
    if (a.size() != b.size())
        return false;

    map<char, int> mp;

    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
        mp[b[i]]--;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (mp[a[i]] != 0)
            return false;
    }

    return true;
}

int main()
{
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a;
    cin >> b;

    bool ans = isAnagram(a, b);

    cout << ans;
    return 0;
}