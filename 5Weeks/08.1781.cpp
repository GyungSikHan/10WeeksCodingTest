//https://www.acmicpc.net/problem/1781
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, d, cup;
vector<pair<int, int>>v;
int main()
{
	cin >> n;

	priority_queue<int,vector<int>, greater<int>> qu;
	for (int i = 0; i < n; i++)
	{
		cin >> d >> cup;
		v.push_back({ d,cup });
	}

	sort(v.begin(), v.end());

	for (auto iter : v)
	{
		qu.push(iter.second);

		if (iter.first < qu.size())
		{
			qu.pop();
		}
	}

	int ret{};
	while (qu.empty() == false)
	{
		ret += qu.top();
		qu.pop();
	}

	cout << ret;
}