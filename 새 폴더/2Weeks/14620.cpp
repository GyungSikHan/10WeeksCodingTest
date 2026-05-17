#include<bits/stdc++.h>

using namespace std;

int dy[4] {0,-1,0,1}, dx[4]{-1,0,1,0};
int n,ret = 987654321;
vector<vector<int>> arr;
vector<vector<bool>> visited;

bool Check(int y, int x)
{
    if(visited[y][x] == true)
        return false;

    for(int i = 0; i < 4; i++)
    {
        int ny = dy[i]+y;
        int nx = dx[i]+x;

        if(ny<0||ny>=n||nx<0||nx>=n)
            return false;
        if(visited[ny][nx] == true)
            return false;
    }
    return true;
}

int Seed(int y, int x)
{
    int sum = arr[y][x];
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int ny = dy[i]+y;
        int nx = dx[i]+x;
        if(ny<0||ny>=n||nx<0||nx>=n)
            return false;
        if(visited[ny][nx] == true)
            return false;
        visited[ny][nx] = true;
        sum+=arr[ny][nx];
    }

    return sum;
}
void DeleteSeed(int y, int x)
{
    visited[y][x] = 0;
    for(int i = 0; i < 4; i++)
    {
        int ny = dy[i]+y;
        int nx = dx[i]+x;

        visited[ny][nx] = false;
    }
}

void flower(int y,int x, int cnt, int cost)//, vector<pair<int, int>> temp)
{
    if(cnt == 3)
    {
        ret = min(ret, cost);
        return;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(Check(i,j) == true)
            {
                int sum = Seed(i,j);
                flower(i,j,cnt+1, cost + sum);
                DeleteSeed(i,j);
            }
        }
    }
}

int main()
{
    cin>>n;
    arr.resize(n,vector<int>(n,0));
    visited.resize(n,vector<bool>(n,false));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            cin>>arr[i][j];
        }
    }

    flower(0,0,0,0);

    cout<<ret;
}