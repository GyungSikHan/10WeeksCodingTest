#include <bits/stdc++.h>

using namespace std;

const string maxTime = "48:00";
int n, team;
string t;
stack<int> st;
string sA, sB;
string retA, retB;

int Mi(string a)
{
    int s = a.find(":");
    string te = a.substr(0, s);
    string te2 = a.substr(s + 1);

    return (stoi(te) * 60) + stoi(te2);
}

int ChangeT(string a, string b)
{
    //cout<<a<<" "<<b<<endl;
    int ateam = Mi(a);
    int bteam = Mi(b);
    //cout << bteam << "-" << ateam << "=" << bteam - ateam << endl;
    return bteam - ateam;
}

string ChangeS(string a, string b)
{
    int temp = ChangeT(a, b);

    string mm = to_string(temp / 60);
    string ss = to_string(temp % 60);
    if (mm.size() == 1)
        mm = "0" + mm;
    if (ss.size() == 1)
        ss = "0" + ss;
    return mm + ":" + ss;
}

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> team >> t;

        if (st.empty() == true || st.top() == team)
        {
            st.push(team);
            if (team == 1 && sA == "")
            {
                sA = t;
            }
            else if (team == 2 && sB == "")
            {
                sB = t;
            }
        }
        else
        {
            int temp = st.top();
            st.pop();
            if (st.empty() == true)
            {
                if (temp == 1)
                {
                    retA = ChangeS(sA, t);
                    sA = "";
                }
                else
                {
                    retB = ChangeS(sB, t);
                    sB = "";
                }
            }
            
        }
    }
    if (sA != "")
    {
        retA = ChangeS(sA, maxTime);
        if (retB == "")
            retB = "00:00";
    }
    if (sB != "")
    {
        retB = ChangeS(sB, "48:00");
        if (retA == "")
            retA = "00:00";
    }
    cout << retA << "\n";
    cout << retB << "\n";
}