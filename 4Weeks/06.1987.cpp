//https://www.acmicpc.net/problem/1987
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };
int r, c, ret;
vector<vector<char>> v;
vector<vector<char>> visited;
vector<char> temp;

void DFS(int x, int y, int count)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx<0||nx>=r||ny<0||ny>=c)
			continue;
		if (visited[nx][ny] == true)
			continue;
		if (find(temp.begin(), temp.end(),v[nx][ny]) != temp.end())
			continue;

		visited[nx][ny] = true;
		temp.push_back(v[nx][ny]);
		DFS(nx, ny, count+1);
		visited[nx][ny] = false;
		temp.pop_back();
	}

	ret = max(ret, count);
}

void DFS(int x, int y, int num, int count)
{
	ret = max(ret, count);
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		int next = 1 << (int)(v[nx][ny] - 'A');
		if ((num & next) == 0)
			DFS(nx,ny, num|next,count +1);
	}
}

int main()
{
	cin >> r >> c;
	v.assign(r, vector<char>(c, {}));
	visited.assign(r, vector<char>(c, 0));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> v[i][j];
	//visited[0][0] = true;
	//temp.push_back(v[0][0] );
	//DFS(0,0,1);

	DFS(0, 0, 1<<(int)(v[0][0] - 'A'), 1);

	cout << ret;
}