#include<bits/stdc++.h>
using namespace std;
int n, m, s, e,dp[2004][2004];
vector<int> v;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	v.resize(n+1,0);
	for (int i = 1; i <= n; i++) 
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) 
	{
		dp[i][i] = 1;
	}
	for (int i = 1; i < n; i++) 
	{
		if (v[i] == v[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int size = 2; size <= n; size++) 
	{
		for (int i = 1; i <= n - size; i++) 
		{
			if (v[i] == v[i + size] && dp[i + 1][i + size - 1])
				dp[i][i + size] = 1;
		}
	}
	cin >> m;
	while (m--) {
		cin >> s>> e;
		cout << dp[s][e] << "\n";
	}
}