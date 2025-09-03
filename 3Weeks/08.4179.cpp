//https://www.acmicpc.net/problem/4179
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int dy[4]{ 0,-1,0,1 }, dx[4]{ -1,0,1,0 };

char map[1001][1001];
int jvisited[1001][1001];
int fvisited[1001][1001];
int r, c;
vector<pair<int, int>> fire;
pair<int, int>je;

void Print(const int visited[1001][1001])
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

void FBFS()
{
	queue<pair<int, int>>q;
	for (auto iter : fire)
		q.push({ iter.first,iter.second });

	while (q.empty() == false)
	{
		int curry = q.front().first;
		int currx = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + curry;
			int nx = dx[i] + currx;

			if (ny < 0 || ny >= r || nx < 0 || nx >=c)
				continue;
			if (map[ny][nx] == '#')
				continue;
			if (fvisited[ny][nx] != 0)
				continue;
			fvisited[ny][nx] = fvisited[curry][currx] + 1;
			q.push({ny,nx});
		}
		Print(fvisited);
	}
}

int JBFS(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });

	while (q.empty() == false)
	{
		int curry = q.front().first;
		int currx = q.front().second;
		q.pop();
		if ((curry == 0 || curry == r-1) || (currx == 0 || currx == c - 1))
			return jvisited[curry][currx];

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + curry;
			int nx = dx[i] + currx;

			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
				continue;
			if (map[ny][nx] != '.')
				continue;
			if (jvisited[ny][nx] != 0)
				continue;
			if (fvisited[ny][nx] != 0 && fvisited[ny][nx] < jvisited[curry][currx]+1)
				continue;
			jvisited[ny][nx] = jvisited[curry][currx] + 1;
			q.push({ ny,nx });
		}
		Print(jvisited);
	}


	return 0;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				jvisited[i][j] = 1;
				je = make_pair(i,j);
			}
			else if (map[i][j] == 'F')
			{
				fvisited[i][j] = 1;
				fire.push_back( make_pair(i, j));
			}
		}
	}

	FBFS();
	int temp = JBFS(je.first, je.second);
	if (temp != 0)
		cout << temp << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}

//문제에서 불이 없을때를 해결하지 못해 틀린 것 같다
//예를 들어
//3 3
//...
//.J.
//...
//이 경우 불이 없다는 예외처리를 하지 않아 IMPOSSIBLE이 나왔었다
//또 불이 여러개 존재할 수 있으므로 불의 위치들을 