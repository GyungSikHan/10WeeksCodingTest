#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int n,m, ret, times;
int a[104][104];
int visited[104][104];

void BFS()
{
    queue<pair<int, int>> qu;
    qu.push({0,0});
    visited[0][0] = 1;
    
    while(qu.empty() == false)
    {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();

        for(int i = 0; i<4;i++)
        {
            int ny = dy[i]+y;
            int nx = dx[i]+x;
            if(ny<0||ny>=n||nx<0||nx>=m)
                continue;
            if(visited[ny][nx] == 1)
                continue;
        
            visited[ny][nx] = 1;
        
            if(a[ny][nx] == 1)
            {
                a[ny][nx] = 0;
                continue;
            }
        
            qu.push({ny,nx});
        }
    }
}
int Check()
{
    int temp{};
    for(int i =0;i<n;i++)
    {
        for(int j = 0; j<m;j++)
        {
            if(a[i][j] == 1)
                temp++;
        }
    }
    return temp;
}
int main()
{
    cin>>n>>m;

    for(int i =0;i<n;i++)
    {
        for(int j = 0; j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 1)
                ret++;
        }
    }

    while(true)
    {
        memset(visited,0,sizeof(visited));
        times++;
        BFS();
        int temp = Check();
        //cout<<temp<<endl;
        if(temp == 0)
            break;
        ret = temp;
    }

    cout<<times<<"\n";
    cout<<ret<<"\n";
}