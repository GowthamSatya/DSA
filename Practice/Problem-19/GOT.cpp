#include <iostream>
#include <vector>
#define lt long int
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        lt total = 0, intro_sum = 0, season_time = 0;
        lt s;

        cin >> s;
        lt intro[s];

        for (lt i = 0; i < s; i++)
            cin >> intro[i];

        for (lt i = 0; i < s; i++)
            intro_sum += intro[i];
        lt k = 0;
        for (lt i = 0; i < s; i++)
        {
            lt si;
            cin >> si;
            lt season[si];
            for (lt j = 0; j < si; j++)
                cin >> season[j];

            for (lt j = 0; j < si; j++)
                season_time += (season[j] - intro[k]);
            k++;
        }

        total = season_time + intro_sum;
        cout << total << endl;
    }
}