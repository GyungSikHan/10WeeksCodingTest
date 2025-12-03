#include<bits/stdc++.h>

using namespace std;

int n,m;
map<int, string> ma;
map<string, int> ma2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    string s;
    for(int i = 1; i <= n; i++)
    {
        cin>>s;
        ma.insert({i,s});
        ma2.insert({s,i});
    }
    
    for(int i = 0; i < m; i++)
    {
        cin>>s;
        if(s[0] >='A' && s[0] <='Z')
        {
            cout<<ma2[s]<<"\n";
        }
        else
        {
            cout<<ma[stoi(s)]<<"\n";
        }
    }

    
}