#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>v;
long long dp[104][21];

long long go(int idx, int sum)
{
	if (sum < 0 || sum > 20)
		return 0;
	
	long long & ret = dp[idx][sum];

	if (ret)
		return ret;
	if (idx == n-2)
	{
		if (sum == v[n - 1])
			return 1;
		return 0;
	}

	ret +=go(idx + 1,sum+ v[idx + 1]);
	ret +=go(idx + 1,sum- v[idx + 1]);
	
	return ret;
}

int main()
{
	cin >> n;
	v.resize(n,0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout<< go(0, v[0]);
}

//dp를 [idx][sum]을 기준으로 되는지 안되는지 판단, 0 or 1