#include <iostream>
#include <vector>

using namespace std;

int t, n, m, a, b;
int head;


bool DFS(int x, const vector<vector<int>>& v, vector<int>& visited, vector<int>& edge)
{
	visited[x] = 1;
	bool bo{};
	for (auto iter : v[x])
	{
		if (visited[iter] == 0)
		{
			edge[x]--;
			edge[iter]--;
			bo = DFS(iter, v, visited, edge);
		}
		else if (visited[iter] != 0 && edge[x] != 0)
			return true;

	}

	return bo;
}

int main()
{
	cin >> t;
	while (t != 0)
	{
		t--;
		cin >> n >> m;
		vector<vector<int>> v(n + 1);
		vector<int> visited(n + 1, 0);
		vector<int> edge(n + 1, 0);
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			edge[a]++;
			edge[b]++;
		}
		if (n-m != 1)
		{
			cout << "graph" << "\n";
			continue;
		}

		int count{};
		bool bo{};
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				count++;
				if (count > 1)
				{
					bo = true;
					break;
				}
				bo = DFS(i, v, visited, edge);
				if (bo == true)
					break;
			}
		}
		if (bo == true)
			cout << "graph\n";
		else
			cout << "tree\n";
	}
}