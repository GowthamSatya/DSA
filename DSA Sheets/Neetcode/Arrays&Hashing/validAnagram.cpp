#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/valid-anagram/

bool isEqual(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

bool isAnagram(string s, string t)
{
    int s1[26] = {0};
    int s2[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        s1[s[i] - 'a']++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        s2[t[i] - 'a']++;
    }

    return isEqual(s1, s2);
}