#include <iostream>
using namespace std;

void input(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void swap(char a, char b)
{
    char temp = a;
    a = b;
    b = temp;
}

void output(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void sort(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (int(a[i]) > int(a[j]))
            {

                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        char A[n], B[n], C[2 * n];

        input(A, n);
        input(B, n);

        sort(A, n);
        sort(B, n);
        int k = 0;

        for (int i = 0; i < 2 * n; i += 2)
        {
            C[i] = A[k];
            C[i + 1] = B[n - k - 1];
            k++;
        }
        output(C, 2 * n);
    }
}