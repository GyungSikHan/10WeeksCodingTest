//https://www.acmicpc.net/problem/14890 v
#include <iostream>
#include <vector>

using namespace std;

int n, l, l2;
vector<vector<int>>v1;
vector<vector<int>>v2;
int ret;

void Solution(vector<vector<int>> v)
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		int j{};
		for (j= 0; j < n-1; j++)
		{
			if (v[i][j] == v[i][j + 1])
				count++;
			else if (v[i][j] + 1 == v[i][j + 1] && count >= l)
				count = 1;
			else if (v[i][j] - 1 == v[i][j + 1] && count >= 0)
				count = -l + 1;
			else
				break;
		}
		if (j == n - 1 && count >= 0)
			ret++;
	}
}

int main()
{
	cin >> n >> l;
	v1.assign(n, vector<int>(n, 0));
	v2.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v1[i][j];
			v2[j][i] = v1[i][j];
		}
	}

	Solution(v1);
	Solution(v2);
	cout << ret;
}