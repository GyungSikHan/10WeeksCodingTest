//https://www.acmicpc.net/problem/1931 v
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int n;
int s, e, counts;
vector<pair<int, int>> v;
vector<pair<int, int>>temp;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back(make_pair(e, s));
	}

	sort(v.begin(), v.end());
	s = v[0].second;
	e = v[0].first;
	temp.push_back({ s,e });

	for (int i = 1; i < n; i++)
	{
		if (v[i].second >= e)
		{
			s = v[i].second;
			e = v[i].first;
			temp.push_back({ s,e });
			counts++;
		}
	}

	for (pair<int, int> i : temp)
		cout << i.first << " " << i.second << endl;
	cout << counts+1;
}