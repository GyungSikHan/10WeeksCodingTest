//https://www.acmicpc.net/problem/2234
#include <iostream>
#include <vector>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };

int n, m;
int arr[51][51];
int visited[51][51];
int pa[51];
int cnt, h = -1, sum;

void DFS(int x, int y, int num)
{
	if (visited[x][y] != 0)
		return;
	h++;
	visited[x][y] = num;
	for (int i = 0; i < 4; i++)
	{
		if ((arr[x][y] & 1<<i) == 0)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			DFS(nx,ny,num);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int num = 1;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				h = 0;
				DFS(i,j,num);
				pa[num] = h;
				cnt = max(cnt,h);
				num += 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i+1 < m)
			{
				int a = visited[i][j];
				int b = visited[i + 1][j];
				if (a != b)
					sum = max(sum, pa[a] + pa[b]);
			}
			if (j + 1 < n)
			{
				int a = visited[i][j];
				int b = visited[i][j+1];
				if (a != b)
					sum = max(sum, pa[a] + pa[b]);
			}
		}
	}
	cout << num-1 << "\n";
	cout << cnt << "\n";
	cout << sum;
}