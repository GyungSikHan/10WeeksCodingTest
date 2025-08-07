//https://www.acmicpc.net/problem/10709
#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<vector<int>> ret;

void Solution()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (j != 0 && ret[i][j] != 0 && ret[i][j - 1] != -1)
			{
				ret[i][j] = ret[i][j - 1] + 1;
			}
		}
	}
}

int main()
{
	cin >> h >> w;
	ret.assign(h, vector<int>(w, -1));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c{};
			cin >> c;
			if (c == 'c')
				ret[i][j] = 0;
		}
	}

	Solution();

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}