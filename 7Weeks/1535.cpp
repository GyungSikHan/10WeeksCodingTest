#include<bits/stdc++.h>

using namespace std;

int n,ret = -987654321;
vector<int> v, v2;

void Solution(int hp, int happy, int idx)
{
	if (hp<= 0)
	{
		ret = max(ret , happy - v2[idx - 1]);
		return;
	}
	if (idx == n)
	{
		ret = max(ret, happy);
		return;
	}
	for (int i = idx; i< n; i++)
	{
		Solution(hp - v[i], happy + v2[i], i + 1);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	v.resize(n, 0);
	v2.resize(n,0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
		cin >> v2[i];

	for (int i = 0; i< n; i++)
	{
		Solution(100, 0 ,i);
	}

	cout << ret;
}