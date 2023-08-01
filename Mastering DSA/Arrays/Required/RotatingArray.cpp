#include <bits/stdc++.h>
using namespace std;

void display_arr(vector<int> arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void left_rotate(vector<int> arr, int offset)
{
    // The Juggling Algorithm
    int n = arr.size();
    offset = offset % n; // offset must be less than n;

    int _gcd = gcd(n, offset);

    for (int i = 0; i < _gcd; i++)
    {
        // store the start value in temp
        int temp = arr[i];
        int j = i;

        /*
            this while loop will traverse and shift elements left
            in each set
        */
        while (1)
        {
            int k = j + offset;

            if (k >= n)
                k -= n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }

        arr[j] = temp;
    }

    display_arr(arr);
}

void right_rotate(vector<int> arr, int offset)
{
    int n = arr.size();
    offset = offset % n; // offset must be less than n;

    // reverse the last 'offset' elements
    for (int i = n - offset, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // reverse the first 'n-offset' elements
    for (int i = 0, j = n - offset - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // reverse the whole array
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    display_arr(arr);
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << "Right Rotated : ";
    right_rotate(arr, 3);
    cout << "Left Rotated : ";
    left_rotate(arr, 3);
    return 0;
}