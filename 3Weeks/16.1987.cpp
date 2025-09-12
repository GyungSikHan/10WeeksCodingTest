//https://www.acmicpc.net/problem/1987 v
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };

int r, c;
char arr[21][21];
int visited[26];
vector<char> v;
int ret;

void DFS(int x, int y, int count)
{
	ret = max(ret, count);

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		int next = arr[nx][ny] - 'A';
		if (visited[next] != 0)
			continue;
		visited[next] = 1;
		DFS(nx,ny,count+1);
		visited[next] = 0;
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	visited[arr[0][0] - 'A'] = 1;
	DFS(0,0,1);

	cout << ret;
}