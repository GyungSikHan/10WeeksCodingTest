//https://www.acmicpc.net/problem/17471 v
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
int n;
int arr[11];
int comp[11];
int visited[11];
vector<int> adj[11];
int ret = INF;

pair<int, int> DFS(int here, int value)
{
	visited[here] = 1;
	pair<int, int> sum = { 1,arr[here] };
	for (int there : adj[here])
	{
		if (comp[there] != value)
			continue;
		if (visited[there] != 0)
			continue;

		pair<int, int> temp = DFS(there,value);
		sum.first += temp.first;
		sum.second += temp.second;
	}

	return sum;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		int a{};
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b{};
			cin >> b;

			adj[i].push_back(b);
			adj[b].push_back(i);
		}
	}

	for (int i = 1; i < (1<<n); i++)
	{
		fill(comp,comp+11, 0);
		fill(visited,visited+11, 0);
		int index = -1, index2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				index = j + 1;
			}
			else
				index2 = j + 1;
		}

		pair<int, int> com1 = DFS(index,1);
		pair<int, int> com2 = DFS(index2,0);
		if (com1.first + com2.first == n)
			ret = min(ret, abs(com1.second - com2.second));
	}

	if (ret == INF)
		cout << -1;
	else
		cout << ret;

}