//https://www.acmicpc.net/problem/16234 
#include <iostream>
#include <vector>

using namespace std;
int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };
int n, l, r;
vector<vector<int>> map;
vector<vector<bool>> visited;

int sum{};
int counts{};

void Check(const vector<pair<int, int>>& ret, vector<vector<int>>& temp)
{
	sum /= ret.size();
	for (pair<int, int> iter : ret)
		temp[iter.first][iter.second] = sum;

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}*/
}
void  DFS(int x, int y, vector<pair<int, int>>& ret)
{
	visited[x][y] = true;
	sum += map[x][y];
	ret.push_back({x,y});
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx<0||nx>=n||ny <0 || ny >= n)
			continue;
		if (visited[nx][ny] == true)
			continue;

		int temp = abs(map[x][y] - map[nx][ny]);
		if (temp >= l && temp <= r)
			DFS(nx,ny, ret);
	}
}
bool Solution()
{
	visited.assign(n, vector<bool>(n, 0));
	vector<vector<int>> temp = map;
	bool b{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				vector<pair<int, int>> ret;
				sum = 0;
				DFS(i, j, ret);
				if (sum != map[i][j])
				{
					Check(ret, temp);
					b = true;
				}
			}
		}
	}

	map = temp;

	if (b == true)
		counts++;

	return b;
}
int main()
{
	cin >> n >> l >> r;
	map.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	while (true)
	{
		if (Solution() == false)
			break;
	}
	
	cout << counts << endl;
}