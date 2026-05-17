#include <bits/stdc++.h>

using namespace std;
int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int n,m;
vector<vector<int>> v;
int dp[54][54];
int visited[54][54];
int cnt;
int go(int y, int x)
{
    if(y < 0 || y >= n || x < 0 || x >= m)
        return 0;
    if(v[y][x] == -1)
        return 0;
    if(visited[y][x] == 1)
        return INF; 
    visited[y][x] = 1; 
    int& ret = dp[y][x];
    if(ret != -1)
        return ret;

    for(int i = 0; i < 4; i++)
    {
        int ny = dy[i]* v[y][x] +y;
        int nx = dx[i]* v[y][x] +x;
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue; 

        ret = max(ret, ?)
        if(int temp = go(ny, nx) != -1)
            ret += temp;
        else
        {
            ret = -1;
            break;
        }
        visited[ny][nx] = 0;
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    v.resize(n,vector<int>(m,0))ź

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m ; j++)
        {
            int temp;
            cin>>temp;
            if(temp == 'H')
                temp = -1;
            v[i][j] = temp;
        }
    }
    go() 
    if(ret == INF) -1

    visited[0][0] = 1;
}