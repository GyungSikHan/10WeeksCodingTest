#include<bits/stdc++.h>

using namespace std;

int n, m, s, e;
vector<int> v;
int dp[2004][2004];

int main()
{
    cin>>n;
    v.resize(n+5, 0);
    for(int i = 1; i <= n; i++)
        cin>>v[i];

    for(int i = 1; i<= n; i++)
        dp[i][i] = 1;
    for(int i = 1; i<=n; i++)
    {
        if(v[i] == v[i+1])
            dp[i][i+1] = 1;
    }

    for(int size = 2; size <= n; size++)
    {
        for(int i = 1; i<=n; i++)
        {
            if(v[i] == v[i+size] && dp[i+1][i+size-1])
                dp[i][i+size] = 1;
        }
    }


    cin>>m;
    while(m--)
    {
        cin>>s>>e;
        cout<<dp[s][e]<<"\n";
    }
}