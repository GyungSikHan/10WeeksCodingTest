#include <bits/stdc++.h>
#include<string>
using namespace std;

int n, t, t1,t2, sum1, sum2;
string times, prvs;

int ChangeString(string s, string s2)
{
    int data = s.find(':');
    int a = stoi(s.substr(0,data))*60 + stoi(s.substr(data+1));
    int b = stoi(s2.substr(0,data))*60+stoi(s2.substr(data+1));

    return b - a;
}
string ChangeInt(int i)
{
    string m =to_string(i/60);
    string s = to_string(i%60);

    if(m.size() == 1)
        m = "0"+m;
    if(s.size() == 1)
        s = "0"+s;
    return m+":"+s;
}
int main()
{
    cin>>n;

    for(int i = 0; i<n;i++)
    {
        cin>>t>>times;

        if(t1 > t2)
        {
            sum1 += ChangeString(prvs, times);
            
        }
        else if(t2 > t1)
        {
            sum2 += ChangeString(prvs, times);
        }

        if(t == 1)
        {
            t1++;
        }
        else 
        {
            t2++;
        }

        prvs = times;
    }

    if(t1 > t2)
    {
        sum1+=ChangeString(prvs, "48:00");
    }
    else if(t2 > t1)
    {
        sum2+=ChangeString(prvs, "48:00");
    }

    cout<<ChangeInt(sum1)<<"\n";
    cout<<ChangeInt(sum2)<<"\n";
}