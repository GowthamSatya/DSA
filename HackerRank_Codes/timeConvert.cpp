#include <bits/stdc++.h>
#include <string.h>

using namespace std;

/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
*/

vector<string> split(string s, char br)
{
    vector<string> st;
    string out;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == br)
        {
            st.push_back(out);
            out = "";
        }
        else
        {
            out += s[i];
        }
    }
    st.push_back(out);
    return st;
}

string getAns(vector<string> str)
{
    string out = "";
    out = out + str[0] + ':' + str[1] + ':' + str[2];
    return out;
}

string timeConversion(string s)
{
    vector<string> splitStr = split(s, ':');
    if (s[s.size() - 2] == 'P' and (stoi(splitStr[0]) < 12))
    {
        int t = stoi(splitStr[0]);
        t = 12 + t;
        stringstream ss;
        ss << t;
        string h_out;
        ss >> h_out;
        splitStr[0] = h_out;
        s = getAns(splitStr);
    }
    else if (s[s.size() - 2] == 'A' and (stoi(splitStr[0]) == 12))
    {
        splitStr[0] = "00";
        s = getAns(splitStr);
    }
    else
        s = getAns(splitStr);
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
