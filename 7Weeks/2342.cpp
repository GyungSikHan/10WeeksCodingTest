#include <bits/stdc++.h>

using namespace std;

int dp[5][5][100001];
vector<int>v;

int check(int from, int to)
{
	if (from == 0)
		return 2;
	if (from == to)
		return 1;
	if (abs(from - to) == 2)
		return 4;

	return 3;
}

int go(int y, int x, int target)
{
	if (target == v.size())
		return 0;
	if (dp[y][x][target] != -1)
		return dp[y][x][target];

	int left = go(v[target], x, target + 1) + check(y, v[target]);
	int right = go(y,v[target], target+1)+ check(x,v[target]);

	return dp[y][x][target] = min(left,right);
}

int main()
{
	while (true)
	{
		int data{}; 
		cin >> data;

		if (data == 0)
			break;
		v.push_back(data);
	}

	memset(dp, -1, sizeof(dp));
	cout<<go(0,0,0);
}


//두발이 0이 아닐때 같이 있는 것도 dp에 계산은 하지만 최소 비용에 들어갈 수 없다
//움직이는 발의 위치에 따라 값이 달라지기 때문