//https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int t, n, m, k;
vector<vector<int>> board;
vector<vector<bool>> visited;

void DFS(int x, int y) 
{
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) 
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
      continue;
    if (board[nx][ny] == 0 || visited[nx][ny] == true)
      continue;

    DFS(nx, ny);
  }
}

int main() 
{
  cin >> t;
  while (t > 0) 
  {
    t--;
    int count{};
    cin >> m >> n >> k;
    board.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < k; i++)
    {
      int a{}, b{};
      cin >> a >> b;
      board[b][a] = 1;
    }

    for (int i = 0; i < n; i++) 
    {
      for (int j = 0; j < m; j++) 
      {
        if (board[i][j] == 1 && visited[i][j] == false) 
        {
          count++;
          DFS(i, j);
        }
      }
    }

    cout << count << endl;
  }
}