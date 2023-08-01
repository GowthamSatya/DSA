#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int arr[N][N], visited[N][N];
int n, m;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void flood_fill(int x, int y)
{
    arr[x][y] = 0;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx >= 0 && yy >= 0 && xx < n && yy < m && arr[xx][yy])
            flood_fill(xx, yy);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                c++;
                flood_fill(i, j);
            }
        }
    }
    cout << c << endl;
    return 0;
}