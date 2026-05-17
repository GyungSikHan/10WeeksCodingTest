#include<bits/stdc++.h>

using namespace std;

int n;
long long dp[31][31];

long long go(int whole, int half)
{
    if(whole == 0 && half == 0)
        return 1;
    long long& ret = dp[whole][half];
    if(ret)
        return ret;
    if(whole > 0)
        ret += go(whole - 1, half+1);
    if(half > 0)
        ret+= go(whole, half-1);
    
    return ret;
}
int main()
{
    while (true)
    {   
        memset(dp, 0, sizeof(dp));
        cin>>n;
        if(n == 0 )
            break;

        cout<<go(n,0)<<"\n";        
    }
}