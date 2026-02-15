#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> m;
int dp[20][20][3];

int go(int y, int x, int idx)
{
    //cout << y << " : " << x << " : " << idx << '\n';
    if(y < 0 || y >= n || x < 0 || x >= n)
        return 0;
    if(y == n-1 && x == n-1)
        return 1;

    int& ret = dp[y][x][idx];
    if(ret != -1)
        return ret;
    ret = 0;
    if(idx == 0)
    { 
        if((x+1) < n&& m[y][x+1] != 1)
            ret += go(y,x+1,0);
        if((y+1) <n && (x+1) < n&& m[y+1][x+1] != 1 &&  m[y][x+1] != 1 && m[y+1][x] != 1 )
            ret += go(y+1, x+1, 1);
    }
    else if(idx == 1)
    {
        if((x+1) < n &&m[y][x+1] != 1 )
            ret += go(y, x+1, 0);
        if((y + 1) < n && (x+1) < n && m[y+1][x+1] != 1 &&  m[y][x+1] != 1 && m[y+1][x] != 1)
            ret += go(y+1, x+1, 1);
        if((y+1) <n && m[y+1][x] != 1 )
            ret+= go(y+1,x,2);
    }
    else
    {
        if(y+1 < n && x + 1 < n && m[y+1][x+1] != 1 &&  m[y][x+1] != 1 && m[y+1][x] != 1)
            ret+= go(y+1,x+1, 1);
        if(y+1 < n && m[y+1][x] != 1)
            ret+= go(y+1,x,2);
    }


    return ret;
}

int main()
{
    cin>>n;
    m.resize(n, vector<int>(n, 0));
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>m[i][j];
        }
    }

    cout<< go(0,1,0);
}