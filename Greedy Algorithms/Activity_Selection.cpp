#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ========== ACTIVITY SELECTION PROBLEM ===============
// ==> STATEMENT
// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

// ==> APPROACH AND ALGORITHM
// The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of the previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
// 1) Sort the activities according to their finishing time
// 2) Select the first activity from the sorted array and print it.
// 3) Do the following for the remaining activities in the sorted array.
// …….a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity then select this activity and print it.

bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return a.second < b.second;
}

void printMaxActivities(int s[], int f[], int n)
{
    vector<pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        m.push_back({s[i], f[i]});
    }
    sort(m.begin(), m.end(), cmp);
    // first activity of sorted pair gets selected;
    int i = 0;
    cout << m[i].first << " " << m[i].second << endl;
    for (int j = 1; j < n; j++)
    {

        if (m[j].first >= m[i].second)
        {
            cout << m[j].first << " " << m[j].second << endl;
            i = j;
        }
    }
}

int main()
{
    int s[] = {5, 1, 3, 0, 5, 8};
    int f[] = {9, 2, 4, 6, 7, 9};
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}