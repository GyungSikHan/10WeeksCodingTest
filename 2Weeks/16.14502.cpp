//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>

using namespace std;

int dx[4]{ -1,0,1,0 };
int dy[4]{ 0,-1,0,1 };

vector<vector<int>> board;
vector<vector<bool>> visited;
int n, m;
int maxCount{};

void Print()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int VirusCount()
{
	int count{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				count++;
		}
	}
	return count;
}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (board[nx][ny] != 0 || visited[nx][ny] == true)
			continue;

		board[nx][ny] = 2;
		visited[nx][ny] = true;
		DFS(nx, ny);
	}
}

int Virus()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 2)
				DFS(i, j);
	//Print();
	return VirusCount();
}

void MakeWall(int count)
{
	if (count>=3)
	{
		vector<vector<int>> temp = board;
		vector<vector<bool>> temp2 = visited;
		maxCount = max(maxCount, Virus());
		//Print();
		board = temp;
		visited = temp2;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && visited[i][j] == false)
			{
				board[i][j] = 1;
				visited[i][j] = true;
				MakeWall(count + 1);
				board[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int a{};
	board.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	MakeWall(0);

	cout << maxCount << endl;
}