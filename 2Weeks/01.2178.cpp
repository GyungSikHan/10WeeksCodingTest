//https://www.acmicpc.net/problem/2178 v
#include <cstdio>
#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] ={0,-1,0,1};
int n{},m{};
vector<vector<int>> board;
vector<vector<int>> visited;

void Solution(int x, int y)
{   
    visited[x][y] = 1;
    queue<pair<int,int>>q;
    q.push({x,y});

    while(q.empty() == false)
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = currx+dx[i];
            int ny = curry+dy[i];

            if(nx<0|| nx>=n||ny<0||ny>=m)
                continue;
            if(visited[nx][ny] != 0 || board[nx][ny] == 0)
                continue;
            visited[nx][ny] = visited[currx][curry]+1;
            q.push({nx,ny});
        }
    }
}

int main()
{

    cin>>n>>m;
    board.resize(n, vector<int>(m, 0));
    visited.resize(n,vector<int>(m,false));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf("%1d",&board[i][j]);
        
    if(board[0][0] == 0)
    {
        cout<<0<<endl;
        return 0;
    }

    Solution(0, 0);

    cout<<visited[n-1][m-1]<<endl;
}