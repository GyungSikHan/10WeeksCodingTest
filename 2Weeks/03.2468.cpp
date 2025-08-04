//https://www.acmicpc.net/problem/2468

#include<iostream>
#include<vector>

using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int n, Max;
vector<vector<int>> board;
vector<vector<bool>> visited;

void DFS(int x, int y, int temp)
{
    visited[x][y] = true;
    for(int i = 0;i<4;i++)
    {
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(nx<0||nx>=n||ny<0||ny>=n)
            continue;
        if(board[nx][ny] <= temp || visited[nx][ny] == true)
            continue;

        DFS(nx,ny,temp);
    }
}

int main()
{
    cin>>n;
    board.assign(n,vector<int>(n,0));
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
        {
            cin>>board[i][j];
            Max = max(Max,board[i][j]);
        }

    int temp{};
    int count{};
    while(temp <= Max)
    {
        int tempCount{};
        visited.assign(n, vector<bool>(n,false));
        for(int i = 0; i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] > temp && visited[i][j] == false)
                {
                    tempCount++;
                    DFS(i,j,temp);
                }
            }
        }

        count = max(count,tempCount);
        temp++;
    }

    cout<<count<<endl;
}