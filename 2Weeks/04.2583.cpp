//https://www.acmicpc.net/problem/2583
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int m,n,k;
vector<vector<int>> board;
vector<vector<bool>>visited;
vector<int> Sum;

void DrawBoard(int x1, int y1, int x2, int y2)
{
    for(int i = y1; i < y2; i++)
    {
        for(int j = x1; j < x2;j++)
        {
            board[i][j]+=1;
        }
    }
}

int DFS(int x, int y)
{
    int temp = 1;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx< 0|| nx >= m || ny < 0 || ny >= n)
            continue;
        if(board[nx][ny] != 0 || visited[nx][ny] == true)
            continue;

        temp += DFS(nx, ny);
    }

    return temp;
}

void Print()
{
    for (const auto i : board)
    {
        for(const auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
}

int main()
{
    cin>>m>>n>>k;
    board.assign(m,vector<int>(n,0));
    visited.assign(m,vector<bool>(n,false));

    for(int i = 0; i < k; i++)
    {
        int x1{},x2{},y1{},y2{};
        cin>>x1>>y1>>x2>>y2;
        DrawBoard(x1, y1, x2, y2);
    }
    
    for (int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0 && visited[i][j] == false)
                Sum.push_back(DFS(i,j));
			int a{};
        }
    }
    sort(Sum.begin(), Sum.end());
    cout << Sum.size() << endl;
    for (const int& iter : Sum)
        cout << iter << " ";
}