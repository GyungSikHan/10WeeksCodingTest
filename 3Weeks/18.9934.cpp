//https://www.acmicpc.net/problem/9934 v
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k;
vector<int> v;
vector<int> visited;
vector<vector<int>> ret;

void DFS(int s, int e, int depth)
{
	if (s > e)
		return;
	if (s == e)
	{
		ret[depth].push_back(v[s]);
		return;
	}

	int mid = (s + e) / 2;
	ret[depth].push_back(v[mid]);

	DFS(s, mid - 1, depth + 1);
	DFS(mid+1, e, depth+1);

}

int main()
{
	cin >> k;
	int index = pow(2, k) - 1;
	ret.resize(index);
	visited.assign(index,0);
	for (int i = 0; i < index; i++)
	{
		int a{};
		cin >> a;
		v.push_back(a);
	}
	
	
	DFS(0,index-1,0);

	for (auto iter : ret)
	{
		for (auto iter2 : iter)
		{
			cout << iter2 << " ";
		}
		cout << endl;
	}
}
