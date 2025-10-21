//https://www.acmicpc.net/problem/14469
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, s, e;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());

	int ret{};
	for (auto iter : v)
	{
		if (iter.first > ret)
			ret = iter.first;

		ret += iter.second;
	}

	cout << ret;
}