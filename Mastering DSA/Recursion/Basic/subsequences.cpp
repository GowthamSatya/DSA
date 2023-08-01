#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void print_subseq(int index, vector<int> &arr, vector<int> &list)
{
    if (index >= arr.size())
    {
        print_arr(list);
        return;
    }
    list.push_back(arr[index]);
    print_subseq(index + 1, arr, list); // take the element
    list.pop_back();
    print_subseq(index + 1, arr, list); // skip the element
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> list;
    print_subseq(0, arr, list);
    return 0;
}