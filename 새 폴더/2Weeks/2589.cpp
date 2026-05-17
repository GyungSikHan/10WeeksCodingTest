#include<bits/stdc++.h>

using namespace std;
int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int n,m,ret = -1;
char arr[51][51];
int visited[51][51];

int print()
{
    int count{};
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m ; j++)
        {
            count = max(count, visited[i][j]);
            //cout<<visited[i][j]<<" ";
        }
        //cout<<endl;
    }

    return count;
}

int BFS(int y, int x)
{
    int count{};
    queue<pair<int,int>> qu;
    qu.push({y,x});
    memset(visited, 0,sizeof(visited));
    visited[y][x] = 1;

    while(qu.empty() == false)
    {
        int curry = qu.front().first;
        int currx = qu.front().second;
        qu.pop();
        for(int i = 0; i<4; i++)
        {
            int ny = dy[i] + curry;
            int nx = dx[i]+currx;
            if(ny<0||ny>=n||nx<0||nx>=m)
                continue;
            if(visited[ny][nx] != 0)
                continue;
            if(arr[ny][nx] == 'W')
                continue;
            //cout<<"ny "<<ny<<" nx "<<nx<<endl;
            qu.push({ny,nx});
            visited[ny][nx] = visited[curry][currx] + 1;
        }
       
    }

    count = print();

    return count;
}

int main()
{
    cin>>n>>m;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            if(arr[i][j] == 'L')
            {
                int temp = BFS(i,j);
                ret = max(ret, temp);
            }
        }
    }

    cout<<ret-1;
}