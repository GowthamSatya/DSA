#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1?page=1&curated[]=8&sortBy=submissions

    Input :
    N = 5
    str = "abaab"

    Output:
    3

    Explanation:
    All palindrome substring are : "aba" , "aa" , "baab"

*/

int CountPS(char s[], int n)
{
    // code here
    bool dp[n][n]; // 0 represent false & 1 represent true otherwise use boolean array.

    int cnt = 0;

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = true;
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                    cnt++;
                }
                else
                    dp[i][j] = false;
            }
            else if (s[i] == s[j] && dp[i + 1][j - 1] == true)
            {
                dp[i][j] = true;
                cnt++;
            }
            else
                dp[i][j] = false;
        }
    }
    return cnt;
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
    int N;
    cin >> N;
    char s[N];
    cin >> s;

    int ans = CountPS(s, N);
    cout << ans << endl;
    return 0;
}