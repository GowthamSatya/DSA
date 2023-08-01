#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void solve(int a[], vector<string> &ans, string temp, int N, int idx)
    {
        if (idx == N)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < keys[a[idx]].size(); i++)
        {
            solve(a, ans, temp + keys[a[idx]][i], N, idx + 1);
        }
    }
    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        vector<string> ans;
        string temp;

        solve(a, ans, temp, N, 0);
        return ans;
    }
};

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}