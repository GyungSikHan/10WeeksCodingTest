//https://www.acmicpc.net/problem/1202 v
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v, k, c;
vector<pair<long long, long long>> ju;
vector<long long> backs;
long long ret;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		ju.push_back({ m,v });
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		backs.push_back(c);
	}
	sort(ju.begin(), ju.end());
	sort(backs.begin(), backs.end());

	priority_queue<long long> temp;
	long long count{};
	for (int i = 0; i < k; i++)
	{
		while (count < n && backs[i] >= ju[count].first)
		{
			temp.push(ju[count].second);
			count++;1122
		}

		if (temp.empty() == false)
		{
			ret += temp.top();
			temp.pop();
		}
	}

	cout << ret;
}
