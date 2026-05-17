#include<bits/stdc++.h>

using namespace std;

int INF = 987654321;
int n, k, temp, dp[10001];

int main()
{
    cin>>n>>k;
    fill(dp, dp + 10001, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        for(int j = temp; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j-temp] + 1);
        }
    }

    if(dp[k] == INF)
        cout<<-1;
    else   
        cout<<dp[k];
}