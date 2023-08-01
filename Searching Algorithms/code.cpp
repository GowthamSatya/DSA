#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Search
{
    vector<int> arr;

public:
    Search()
    {
        getInput();
    }

    void getInput()
    {
        int n;
        cout << "Enter the size of arr : ";
        cin >> n;
        arr.resize(n);
        cout << "Enter the elements of arr :\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void linearSearch(int x)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == x)
            {
                cout << "Element " << x << " found at position " << i + 1 << endl;
                return;
            }
        }
        cout << "Element " << x << " not found in array" << endl;
        return;
    }

    void binarySearch(int x)
    {
        sort(arr.begin(), arr.end());
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (arr[m] == x)
            {
                cout << "Element " << x << " found at position " << m + 1 << " in sorted array." << endl;
                return;
            }
            else if (x > arr[m])
                l = m + 1;
            else
                r = m - 1;
        }
        cout << "Element " << x << " not found in array" << endl;
        return;
    }

    void jumpSearch(int x)
    {
        sort(arr.begin(), arr.end());
        int m = floor(sqrt(arr.size()));
        for (int i = 0; i < arr.size(); i += m)
        {
            if (x == arr[i])
            {
                cout << "Element " << x << " found at position " << i + 1 << " in sorted array." << endl;
                return;
            }
            else if (x < arr[i])
            {
                for (int k = i - m; k < i; k++)
                {
                    if (arr[k] == x)
                    {
                        cout << "Element " << x << " found at position " << k + 1 << " in sorted array." << endl;
                        return;
                    }
                }
            }
            else
                continue;
        }
        cout << "Element " << x << " not found in array" << endl;
        return;
    }

    int interpolationSearchUtil(int lo, int hi, int x)
    {
        int pos;
        if (lo <= hi && x >= arr[lo] && x <= arr[hi])
        {
            pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

            if (arr[pos] == x)
                return pos;

            if (arr[pos] < x)
                return interpolationSearchUtil(pos + 1, hi, x);

            if (arr[pos] > x)
                return interpolationSearchUtil(lo, pos - 1, x);
        }

        return -1;
    }

    void interpolationSearch(int x)
    {
        sort(arr.begin(), arr.end());
        int k = interpolationSearchUtil(0, arr.size() - 1, x);

        if (k > 0)
        {
            cout << "Element " << x << " found at position " << k + 1 << " in the sorted array." << endl;
            return;
        }
        else
        {
            cout << "Element " << x << " not found in array." << endl;
            return;
        }
    }
};

int main()
{
    Search *s = new Search();
    int x;
    cout << "Enter Element to search : ";
    cin >> x;
    s->linearSearch(x);
    s->binarySearch(x);
    s->jumpSearch(x);
    s->interpolationSearch(x);
    return 0;
}