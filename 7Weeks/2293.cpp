#include<bits/stdc++.h>

using namespace std;

int n,k,temp, dp[10001], INF = 987654321;
int ret = INF;
vector<int> v;
int go(int sum, int idx)
{
    if(sum > k)
        return 0;
    if(sum == k)
    {
        return 1;
    }

    for(auto a : v)
        dp[idx] += go(sum+a, idx+1);
}
    
int main()
{
    cin>>n>>k;
    v.resize(n,0);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    go(0,1);
    cout<<dp[k];
}