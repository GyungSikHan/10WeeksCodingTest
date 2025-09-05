//https://www.acmicpc.net/problem/14497 v

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };
int n, m;
int cx, cy, x2, y2;

vector<vector<char>> v;
vector<vector<int>> visited;

int main()
{
	cin >> n >> m;
	cin >> cx >> cy >> x2 >> y2;

	if (cx == x2 && cy == y2)
	{
		cout << 1 << endl;
		return 0;
	}

	v.assign(n + 1, vector<char>(m + 1, -1));
	visited.assign(n + 1, vector<int>(m + 1, 0));
	string s{};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> v[i][j];
		}
	}
	queue<pair<int, int>> q;
	visited[cx][cy] = 1;
	q.push({ cx,cy });
	int cnt{};

	while (v[x2][y2] == '#')
	{
		cnt++;
		queue<pair<int, int>>temp;
		while (q.empty() == false)
		{
			int currx = q.front().first;
			int curry = q.front().second;
			q.pop();

			if (currx == x2 && curry == y2)
				break;

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + currx;
				int ny = dy[i] + curry;

				if (nx < 1 || nx >n || ny <1 || ny>m)
					continue;
				if (visited[nx][ny] != 0)
					continue;
				visited[nx][ny] = cnt;
				if (v[nx][ny] != '0')
				{
					v[nx][ny] = '0';
					temp.push({ nx,ny });
				}
				else
					q.push({ nx,ny });
			}
		}

		q = temp;
	}

	cout << visited[x2][y2];
}

//queue 두개를 이용하는 BFS 문제
//거의 이전에 구현했던 BFS들과 비슷하다
//하지만 첫번째 반복문은 v[x2][y2] != '0'이 아닐동안, 즉 범인을 찾기전까지 반복해준다
//여기서 cnt 즉 뛴 횟수를 ++해주는데, 처음부터 뛰기 시작하므로 위해 cnt를 0으로 초기화 하고 cnt를 ++해준것이다, 그리고 두번째 queue	도 만들어준다
//이후 평소 BFS를 구현하면 된다
//첫번째 queue에는 1을 만나기 전 모든 좌표를 push해주고, 두번째 queue에는 1을 만난 좌표를 push해줌
//이 조건이 v[nx][ny]가 '0'이 아닐때, 즉 1이거나 범인이 있다고 가정할때이다
//이후 기존 BFS를 탈출하면 q=temp를 해서 1이었던 지역이나 범인이 있던 지역을 첫번째 queue에 넣어 BFS를 돌면서 다시 탐색할 수 있게 한다
