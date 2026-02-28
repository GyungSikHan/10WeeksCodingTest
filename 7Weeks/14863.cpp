#include <bits/stdc++.h>

using namespace std;

struct datas
{
	int times;
	int pay;
};
int n, k;
vector<datas> w, b;
int dp[104][100004];

int go(int idx, int times)
{
	if (idx == n)
		return 0;
	int& ret = dp[idx][times];
	if (ret)
		return ret;
	ret = -98654321;
	if (times - w[idx].times >= 0)
		ret = std::max(ret, go(idx + 1, times - w[idx].times) + w[idx].pay);
	if (times - b[idx].times >= 0)
		ret = std::max(ret, go(idx + 1, times - b[idx].times) + b[idx].pay);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	w.resize(n);
	b.resize(n);
	for (int i=0;i<n;i++)
	{
		cin >> w[i].times >> w[i].pay >> b[i].times >> b[i].pay;
	}


	cout<<go(0, k);
}