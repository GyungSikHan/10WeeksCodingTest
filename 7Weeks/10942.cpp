#include<bits/stdc++.h>

using namespace std;

int n, m, s, e;
vector<int> v;

bool IsP(int start, int end)
{
    if(start == end)
        return true;
    while(s != e){
        if(v[s] != v[e]){
            return false;
        }s++; e--;
    }
    dp[i][i] = 1; 
    dp[i][i + 1] = 1;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(){
                dp[i][j] = 1;
            }
        }
    }

    return true;
}

int main()
{
    cin>>n;
    v.resize(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }

    cin>>m;

    for(int i = 0; i < m; i++)
    {
        cin>>s>>e;
        cout<<IsP(s,e)<<endl;
    }
}