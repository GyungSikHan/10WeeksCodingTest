//https://www.acmicpc.net/problem/1068 v

#include <iostream>
#include<vector>

using namespace std;

int n, m, root;
vector<vector<int>> node;
vector<bool>visited;
int Count;

int Solution(int data)
{
	int count{};
	visited[data] = true;
	for (int iter : node[data])
	{
		if (visited[iter] == false)
		{
			if (iter != m)
				count += Solution(iter);
		}
	}

	if (count == 0)
		return 1;

	return count;
}

int main()
{
	cin >> n;
	node.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
	{
		int a{};
		cin >> a;
		if (a != -1)
			node[a].push_back(i);
		else
			root = i;
		
	}

	cin >> m;
	if (m != root)
		Count = Solution(root);
	cout << Count << endl;
}

// Root가 무조건 0번 index가 아니라 -1이 입력된 차례가 Root 노드임
// 이를 생각해서 풀면 됨