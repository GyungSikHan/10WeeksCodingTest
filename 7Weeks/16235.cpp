#include<bits/stdc++.h>

using namespace std;
int dy[8]{ 0,-1,-1,-1,0,1,1,1 };
int dx[8]{-1,-1,0,1,1,1,0,-1};
int n, m, k,x,y,z, A[14][14];
int yangbun[14][14];
vector<int> a[14][14];

void SpringSummer()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (a[i][j].size() == 0)
				continue;

			int dieTree{};
			vector<int> temp;

			sort(a[i][j].begin(), a[i][j].end());
			for (int tree: a[i][j])
			{
				if (yangbun[i][j] >= tree)
				{
					yangbun[i][j] -= tree;
					temp.push_back(tree + 1);
				}
				else
					dieTree += tree / 2;
			}
			a[i][j] = temp;
			yangbun[i][j] += dieTree;
		}
	}
}

void Fall()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j].size() == 0)
				continue;

			for (int tree : a[i][j])
			{
				if (tree % 5 == 0)
				{
					for (int d = 0; d < 8; d++)
					{
						int ny = i + dy[d];
						int nx = j + dx[d];

						if (ny<0||ny>= n || nx<0 || nx>= n)
							continue;
						a[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			yangbun[i][j] += A[i][j];
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	fill(&yangbun[0][0], &yangbun[0][0] + 14*14, 5);

	for (int i = 0; i<n;i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i<m;i++)
	{
		cin >> x >> y >> z;
		x--;
		y--;
		a[x][y].push_back(z);
	}

	for (int i = 0; i<k; i++)
	{
		SpringSummer();
		Fall();
		Winter();
	}

	int ret{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret += a[i][j].size();
		}
	}
	cout << ret;
}