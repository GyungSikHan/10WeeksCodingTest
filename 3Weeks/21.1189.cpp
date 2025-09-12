//https://www.acmicpc.net/problem/1189
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };
int r, c, k;
char arr[6][6];
int visited[6][6];
pair<int, int> han;

void Print()
{
		cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int DFS(int x, int y, int count)
{
	
	if (count == k && arr[x][y] == 'h')
	{
		return 1;
	}

	int a{};

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0||nx>=r||ny<0||ny>=c)
			continue;
		if (arr[nx][ny] == 'T' || visited[nx][ny] != 0)
			continue;

		visited[nx][ny] = 1;
		a += DFS(nx,ny,count+1);
		visited[nx][ny] = 0;
	}

	return a;
}

int main()
{
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'T')
				visited[i][j] = 1;
		}
	}
	arr[0][c - 1] = 'h';
	visited[r - 1][0] = 1;
	cout<<DFS(r-1,0,1);
	
}