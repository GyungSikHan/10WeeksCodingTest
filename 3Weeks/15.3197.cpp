//https://www.acmicpc.net/problem/3197 v
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int maxInt = 1501;

int dx[4]{ 0,-1,0,1 };
int dy[4]{ -1,0,1,0 };

int r, c;
char arr[maxInt][maxInt];
int visited[maxInt][maxInt];
int sVisited[maxInt][maxInt];
pair<int, int >swanPos;
queue<pair<int, int>>swan;
queue<pair<int, int>>swantemp;
queue<pair<int, int>>water;
queue<pair<int, int>>watertemp;
int x, y;
int days;

void SwapQueue(queue<pair<int, int>>& q)
{
	queue<pair<int, int>> temp{};
	swap(q,temp);
}

bool MoveSwan()
{
	while (swan.empty() == false)
	{
		x = swan.front().first;
		y = swan.front().second;
		swan.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx<0||nx>=r||ny<0||ny>=c||sVisited[nx][ny] == 1)
				continue;

			if (arr[nx][ny] == 'L')
				return true;

			sVisited[nx][ny] = 1;
			if (arr[nx][ny] == 'X')
				swantemp.push({ nx,ny });
			else
				swan.push({ nx,ny });
		}
	}
	return false;
}

void IceMelts()
{
	while (water.empty() == false)
	{
		x = water.front().first;
		y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] == 1)
				continue;
			if (arr[nx][ny] == 'X')
			{
				visited[nx][ny] = 1;
				arr[nx][ny] = '.';
				watertemp.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'L')
				swanPos = make_pair(i, j);
			if (arr[i][j] != 'X')
			{
				visited[i][j] = 1;
				water.push({ i,j });
			}
		}
	}
	swan.push(swanPos);
	sVisited[swanPos.first][swanPos.second] = 1;

	while (true)
	{
		if (MoveSwan() == true)
			break;
		IceMelts();

		swan = swantemp;
		water = watertemp;

		SwapQueue(swantemp);
		SwapQueue(watertemp);
		days++;
	}

	cout << days;
}