#include <bits/stdc++.h>
using namespace std;

void dutch_national_flag(vector<int> &arr)
{
    int n = arr.size();

    int lo = 0;
    int mid = 0;
    int hi = n - 1;

    while (mid <= hi)
    {
        switch (arr[mid])
        {
            // swap the 0 to lower range and increment lo and mid
        case 0:
            swap(arr[lo++], arr[mid++]);
            break;
        // no change is required as 1 must be in middle range
        case 1:
            mid++;
            break;

        // swap the 2 with element at higher range and decrement only hi
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    dutch_national_flag(arr);

    return 0;
}