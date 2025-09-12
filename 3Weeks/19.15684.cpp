#include <iostream>

using namespace std;

const int INF = 987654321;
int n, m, h;
int a, b;
int bridge[31][11];
int ret = INF;

bool Check()
{
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (bridge[j][start] == 1)
				start++;
			else if (bridge[j][start - 1] == 1)
				start--;
		}
		if (start != i)
			return false;
	}

	return true;
}

void GO(int here, int cnt)
{
	if (cnt > 3 || cnt>ret)
		return;
	if (Check() == true)
	{
		ret = min(ret,cnt);
		return;
	}

	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (bridge[i][j] == 1 || bridge[i][j+1] == 1 || bridge[i][j-1] == 1)
				continue;
			bridge[i][j] = 1;
			GO(i,cnt+1);
			bridge[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		bridge[a][b] = 1;
	}

	GO(1,0);

	cout << (ret == INF ? -1 : ret);
}