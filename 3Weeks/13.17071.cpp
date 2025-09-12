//https://www.acmicpc.net/problem/17071 v
#include <iostream>
#include <queue>

using namespace std;

const int INF = 500000;
int n, k, turn = 1;
int visited[2][INF+4];
bool mit;

int main()
{
	cin >> n >> k;
	if (k == n)
	{
		cout << 0;
		return 0;
	}

	visited[0][n] = 1;
	queue<int> q;
	q.push(n);

	while (q.empty() == false)
	{
		k += turn;
		if (k > INF)
			break;
		if (visited[turn%2][k] != 0)
		{
			mit = true;
			break;
		}

		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int x = q.front();
			q.pop();

			for (int nx: {x-1,x +1,x*2})
			{
				if (nx < 0 || nx > INF || visited[turn % 2][nx])
					continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == k)
				{
					mit = true;
					break;
				}
				q.push(nx);
			}
			if (mit == true)
				break;
		}
		if (mit == true)
			break;
		turn++;
	}

	if (mit == true)
		cout << turn;
	else
		cout << -1;
}