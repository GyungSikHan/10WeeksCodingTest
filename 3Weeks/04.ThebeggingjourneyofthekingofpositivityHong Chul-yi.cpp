#include <iostream>
#include <vector>

using namespace std;

int dx[4]{ -1,0,1,0 };
int dy[4]{ 0,-1,0,1 };

int map[3][3] = {
					10,20,21,
					70,90,12,
					80,110,120
};

bool visited[3][3];
int ret;
vector<int> v;

void Print()
{
	for (int i : v)
		cout << i << " ";
	cout << endl;
}
void Solution(int x, int y)
{
	if (x == 2 && y == 2)
	{
		Print();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx <0 || nx >= 3 || ny <0 || ny >= 3)
			continue;
		if (visited[nx][ny] == true)
			continue;
		visited[nx][ny] = true;
		v.push_back(map[nx][ny]);
		Solution(nx, ny);
		visited[nx][ny] = false;
		v.pop_back();
	}
}

int main()
{
	visited[0][0] = true;
	v.push_back(map[0][0]);
	Solution(0,0);
}