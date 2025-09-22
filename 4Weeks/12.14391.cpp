#include <iostream>
#include <vector>

using namespace std;
int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };

int n, m, ret;
int arr[25];
int visited[25];
vector<pair<int, int >>pos;
void DFS(int x, int y)
{

	int px = pos[1].first - pos[0].first;
	int py = pos[1].second - pos[0].second;
	if ()
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx< 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (visited[nx*n+ny] != 0)
			continue;
		visited[nx * n + ny] = 1;
		pos[1].first = nx;
		pos[1].second = ny;
		DFS(nx, ny);
		visited[nx * n + ny] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i*n+j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i*n+j] == 0)
			{
				pos.push_back({ i,j });
				pos.push_back({ i,j });
				visited[i*n+j] = 1;
				DFS(i,j);
				visited[i*n+j] = 0;
			}
		}
	}
}