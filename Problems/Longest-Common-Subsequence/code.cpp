#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int LCS_R(char s1[], char s2[], int l1, int l2,int m,int n){
    if(l1 == m or l2 == n) return 0;
    static int ans = 0;
    if(s1[l1] == s2[l2]){
        ans = 1 + LCS_R(s1, s2, l1+1, l2+1,m,n);
    }else{
        ans = 0 + max(LCS_R(s1, s2, l1+1, l2,m,n), LCS_R(s1, s2, l1, l2+1,m,n));
    }
    return ans;
}

int LCS(char w1[], char w2[], int n1, int n2)
{
    int L[n1 + 1][n2 + 1];
    int i, j;

    for (i = 0; i <= n1; i++)
    {
        for (j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (w1[i - 1] == w2[j - 1])
            {
                cout << w1[i - 1] << " " << w2[i - 1] << endl;
                L[i][j] = L[i - 1][j - 1] + 1;
            }

            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    return L[n1][n2];
}

int main()
{
    char w1[] = "AGGTAB";
    char w2[] = "GXTXAYB";

    int m = strlen(w1);
    int n = strlen(w2);
    cout << m << " " << n << endl;
    cout << LCS(w1, w2, m, n);
    cout << " " << LCS_R(w1,w2,0,0,m,n) << endl;
}