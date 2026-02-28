#include <bits/stdc++.h>

using namespace std;
const int mod = 1000007;
int n, m, c;
vector<vector<int>> v;
int dp[54][54][54][54];

int go(int y, int x,int cnt, int cnt2)
{
	if (y > n || x > m)
		return 0;
	if (y == n && x == m)
	{
		if (cnt == 0 && v[y][x] == 0)
			return 1;
		if (cnt == 1 && v[y][x] > cnt2)
			return 1;
		return 0;
	}
	int& ret = dp[y][x][cnt][cnt2];
	if (ret != -1)
		return ret;
	ret = 0;
	if (v[y][x] == 0)
		ret = (go(y + 1, x, cnt, cnt2) + go(y, x+1, cnt, cnt2) )% mod;
	else if (v[y][x]> cnt2)
		ret =( go(y + 1, x, cnt-1, v[y][x]) + go(y, x+1, cnt-1, v[y][x]) )% mod;

	return  ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> c;
	v.resize(n+1, vector<int>(m+1, 0));
	for (int i = 1; i<=c; i++)
	{
		int y{}, x{};
		cin >> y >> x;
		v[y][x]= i;
	}
	memset(dp, -1, sizeof(dp));
	
	for (int i = 0; i <= c; i++)
		cout << go(1, 1, i, 0) << " ";

}