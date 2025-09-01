//https://www.acmicpc.net/problem/2636 v
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<vector<int>> board;
vector<vector<bool>> visited;
int n, m, times, ret;

int Print()
{
	//cout << endl;
	int count{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == true)
				board[i][j] = 0;
			if (board[i][j] == 1)
				count++;
			//cout << board[i][j] << " ";
		}
		//cout << endl;
	}

	//cout << count << endl;
	return count;
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (visited[nx][ny] == false)
		{
			if (board[nx][ny] == 1)
				visited[nx][ny] = true;
			else
				DFS(nx,ny);
		}
	}
}

int main()
{
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
		
	int temp{};
	while (true)
	{
		ret = temp;
		temp = Print();
		if (temp == 0)
			break;
		visited.assign(n, vector<bool>(m, false));
		DFS(0,0);
		times++;
	}

	cout << times << endl;
	cout << ret << endl;
}