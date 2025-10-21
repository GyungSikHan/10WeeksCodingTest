//https://www.acmicpc.net/problem/2170
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n;
int x, y;
pair<int,int> v[1000001];
//vector<pair<int, int >>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	//v.resize(n, pair<int, int>({}));
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v[i] = make_pair(x,y);
	}

	sort(&v[0], &v[0] + n);
	int start = v[0].first, end = v[0].second, sum{};
	for (int i = 1; i < n; i++)
	{
		if (v[i].first > end)
		{
			sum += end - start;
			start = v[i].first;
			end = v[i].second;
		}
		else if (v[i].first <= end && v[i].second >= end)
			end = v[i].second;
	}

	sum += end - start;

	cout << sum;
}