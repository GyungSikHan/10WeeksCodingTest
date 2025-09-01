//https://www.acmicpc.net/problem/1325
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> Count;
vector<vector<int>> com;


int Solution(vector<bool>& visited, int data)
{
	visited[data] = true;
	int count = 1;
	for (int iter : com[data])
	{
		if (visited[iter] == true)
			continue;
		count += Solution(visited, iter);
	}

	return count;
}

int main()
{
	cin >> n >> m;
	com.resize(n+1);

	for (int i = 0; i < m; i++)
	{
		int a{}, b{};
		cin >> a >> b;
		com[b].push_back(a);
	}

	int Max{};
	for (int i = 1; i <= n; i++)
	{
		vector<bool> visited(n+1, false);
		int temp = Solution(visited, i);
		if (Max == temp)
			Count.push_back(i);
		else if (Max < temp)
		{
			Max = temp;
			Count.assign(0,0);
			Count.push_back(i);
		}
	}

	sort(Count.begin(),Count.end());

	for (int iter : Count)
		cout << iter << " ";
	
}