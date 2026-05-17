#include<bits/stdc++.h>

using namespace std;

int n, m, c;
vector<int> v;
int dp[11][21][1 << 14];


int Solution(int backCount, int sum, int bit)
{
    if(backCount == m)
    {        
        return 0;
    }

    int& ret = dp[backCount][sum][bit];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i = 0; i < n; i++)
    {
        if((bit & (1 << i)))
            continue;
        if(sum + v[i] <= c)
        {
            ret = max(ret, Solution(backCount, sum + v[i], bit | (1 << i)) + 1);
        }
        ret = max(ret, Solution(backCount+1, 0, bit));
    }

    return ret;
}

int main()
{
    cin>>n>>m>>c;
    v.resize(n,0);
    memset(dp, -1, sizeof(dp));

    for(int i =0; i < n; i++)
        cin>>v[i];
    
    sort(v.begin(), v.end());
    
    cout<< Solution(0,0,0);
}