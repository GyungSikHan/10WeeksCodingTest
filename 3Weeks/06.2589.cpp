//https://www.acmicpc.net/problem/2589 v
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };
char map[51][51];
int n, m;
set<pair<int, int>>se;

void Print(const int visited[51][51])
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int BFS(int x, int y)
{
	int temp{};
	int visited[51][51]{};
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });

	while (q.empty() == false)
	{
		int currx = q.front().first;
		int curry = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + currx;
			int ny = dy[i] + curry;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == 'W')
				continue;

			if (visited[nx][ny] != 0)
				continue;

			visited[nx][ny] = visited[currx][curry] + 1;
			q.push({nx,ny}	);
		}
		//Print(visited);
		temp = max(temp, visited[currx][curry]);
	}

	return temp-1;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int ret{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				ret = max(ret,BFS(i,j));
			}
		}
	}

	cout << ret << endl;
}

//dfs가 아닌 bfs로 풀면 쉽게 풀수있는 문제였는데 dfs를 고집해 오래걸렸음...ㅠ