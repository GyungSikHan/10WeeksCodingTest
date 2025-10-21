//https://www.acmicpc.net/problem/2109
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, p, d;
vector<pair<int, int>> v;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());
	priority_queue<int,vector<int>, greater<int> > q;
	int sum{};
	for (int i = 0; i < n; i++)
	{
		q.push(v[i].second);

		if (q.size() > v[i].first)
			q.pop();
	}

	while (q.empty() == false)
	{
		sum += q.top();
		q.pop();
	}

	cout << sum;
}