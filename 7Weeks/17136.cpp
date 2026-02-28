#include<bits/stdc++.h>

using namespace std;
int dy[4]{ 0,-1,0,1 }, dx[4]{ -1,0,1,0 };
vector<pair<pair<int, int>, int>> v;
int maps[10][10], visited[10][10];
int zeroCount{};
vector<pair<int, int>> v2;

int go(int y, int x)
{
	if (visited[y][x] != 0)
		return 0;

	queue<pair<int, int>>qu;
	qu.push({ y,x });
	visited[y][x] = 1;
	int vTemp[10][10];
	memcpy(vTemp, visited, sizeof(vTemp));

	while (qu.empty() == false)
	{
		int curry = qu.front().first;
		int currx = qu.front().second;
		qu.pop();
		for (int i = 0; i<4; i++)
		{
			int ny = dy[i] + curry;
			int nx = dx[i] + currx;
			if (ny<0 || ny>=10||nx<0||nx>= 10)
				continue;
			if (vTemp[ny][nx] != 0)
				continue;

			qu.push({ ny,nx });
			vTemp[ny][nx] += vTemp
		}
	}
}

int main()
{
	for (int i = 1; i <= 5; i++)
		v.push_back({ {i,i},5 });
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 0)
				zeroCount++;
			else
				v2.push_back({ i,j });
		}
	}

	if (zeroCount == 100)
	{
		cout << 0;
		return 0;
	}

	for (const auto& i : v2)
	{
		go(i.first, i.second);
	}
}