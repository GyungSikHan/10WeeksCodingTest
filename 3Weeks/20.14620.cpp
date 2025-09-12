//https://www.acmicpc.net/problem/14620
#include <iostream>
#include <vector>
#include <queue>
#include <random>

using namespace std;

int dx[4]{ 0,-1,0,1 }, dy[4]{ -1,0,1,0 };

int n;
vector<vector<int>> v;
vector<vector<int>> visited;
vector<int> ret;
int r = 987654321;
void Print(vector<vector<int>> v)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

}
int Seed(int x, int y, vector<vector<int>>& visit)
{
	vector<pair<int, int>>pos;

	int price = v[x][y];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny] != 0)
			return -1;
		price += v[nx][ny];
		pos.push_back({ nx,ny });
	}
	for (auto iter : pos)
		visit[iter.first][iter.second] = 1;
	return price;
}

bool Solution(int& sum)
{
	vector<vector<int >> visitedt;
	int price = 987654321;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (visited[i][j] == 0)
			{
				vector<vector<int>> tempVisited = visited;
				tempVisited[i][j] = 1;
				int temp = Seed(i, j, tempVisited);
				if (temp != -1)
				{
					if (price > temp)
					{
						visitedt = tempVisited;
						//Print(visitedt);
						price = temp;
					}
					//price = min(price, temp);
					
				}
			}
	if (price == 987654321)
		return false;
	sum += price;
	visited = visitedt;
	return true;
}

bool Check(int x, int y)
{
	if (visited[x][y] == 1)
		return false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1)
			return false;
	}

	return true;
}
void DeleteFlower(int x, int y)
{
	visited[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = 0;
	}
}
int Seed(int x, int y)
{
	int sum = v[x][y];
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1)
			return false;
		visited[nx][ny] = 1;
		sum += v[nx][ny];
	}


	return sum;
}

void flower(int x,int y, int count, int sum)
{
	if (count == 3)
	{
		r = min(r,sum);
		return ;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Check(i, j) == true)
			{
				flower(i, j, count + 1, sum+Seed(i, j));
				DeleteFlower(i,j);
			}
		}
	}
}

int main()
{
	cin >> n;
	v.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	//int ret = 987654321;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		visited.assign(n, vector<int>(n, 0));
	//		int temp = Seed(i, j,visited);
	//		visited[i][j] = 1;
	//		if (temp != -1)
	//		{
	//			if (Solution(temp) != -1)
	//				if (Solution(temp) != -1)
	//				{
	//					//Print(visited);
	//					ret = min(ret, temp);
	//				}

	//		}
	//	}
	//}
	//cout << ret;

	flower(0,0,0,0);
	cout << r;
}