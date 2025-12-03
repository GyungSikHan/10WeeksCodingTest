#include<bits/stdc++.h>
using namespace std;

int n, len;
string s, s2;

int main()
{
    cin>>n;
    cin>>s;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '*')
        {
            len = i;
            break;
        }
    }

    string t = s.substr(0, len);
    string t2 = s.substr(len+1);

    for(int i = 0; i < n; i++)
    {
        cin>>s2;

        if(s2.size() < t.size() || s2.size() < t2.size() )
            cout<<"NE\n";
        else if(s2.substr(0, t.size()) != t|| s2.substr(s2.size()-t2.size()) != t2)
            cout<<"NE\n";
        else
            cout<<"DA\n";
    }
}