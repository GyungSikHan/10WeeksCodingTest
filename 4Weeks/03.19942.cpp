// https://www.acmicpc.net/problem/19942
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//내가 푼 방법
//const int INF = 987654321;
//int n;
//int mp, mf, ms, mv;
//vector<vector<int>> v;
//int ret = INF;
//vector<int> node;
//
//void Solution(int x, int sum, vector<int> temp, vector<int> t)
//{
//	if (temp[0] >= mp && temp[1] >= mf && temp[2] >= ms && temp[3] >= mv)
//	{
//		if (ret > sum)
//		{
//			ret = sum;
//			node = t;
//		}
//		return;
//	}
//
//	for (int i = x + 1; i <= n; i++)
//	{
//		temp[0] += v[i][0];
//		temp[1] += v[i][1];
//		temp[2] += v[i][2];
//		temp[3] += v[i][3];
//		t.push_back(i);
//		Solution(i, sum + v[i][4], temp, t);
//		t.pop_back();
//		temp[0] -= v[i][0];
//		temp[1] -= v[i][1];
//		temp[2] -= v[i][2];
//		temp[3] -= v[i][3];
//	}
//}
//
//int main()
//{
//	cin >> n;
//	cin >> mp >> mf >> ms >> mv;
//	v.assign(n + 1, vector<int>(5, 0));
//	for (int i = 1; i <= n; i++)
//		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
//
//	for (int i = 1; i <= n; i++)
//	{
//		vector<int> t;
//		vector<int> temp;
//		t.push_back(i);
//		temp.push_back(v[i][0]);
//		temp.push_back(v[i][1]);
//		temp.push_back(v[i][2]);
//		temp.push_back(v[i][3]);
//		Solution(i, v[i][4], temp, t);
//	}
//
//	if (ret == INF)
//		cout << -1;
//	else
//	{
//		cout << ret << "\n";
//		for (int i : node)
//			cout << i << " ";
//	}
//
//}

//비트마스킹을 활용한 방법
const int INF = 987654321;
int n, mp, mf, ms, mv;
struct A
{
	int p, f, s, v, cost;
} arr[16];
int b, c, d, e, sum;
int ret = INF;
map<int, vector<vector<int>>> ret_v;

int main()
{
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
		cin >> arr[i].p>>arr[i].f>>arr[i].s>>arr[i].v>>arr[i].cost;

	for (int i = 1; i < (1<<n); i++)
	{
		b = c = d = e = sum = 0;
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			if (i&(1<<j))
			{
				v.push_back(j+1);
				b += arr[j].p;
				c += arr[j].f;
				d += arr[j].s;
				e += arr[j].v;
				sum += arr[j].cost;
			}
		}
		if (b>=mp&& c>=mf&& d >= ms && e>=mv)
		{
			if (ret >= sum)
			{
				ret = sum;
				ret_v[ret].push_back(v);
			}
		}
	}

	if (ret == INF)
		cout << -1;
	else
	{
		sort(ret_v[ret].begin(),ret_v[ret].end());
		cout << ret << "\n";
		for (int i : ret_v[ret][0])
			cout << i << " ";
	}
}