//https://www.acmicpc.net/problem/17471 v
#include <iostream>
#include <vector>

using namespace std;
const int INF = 987654321;
int n;
string a;
int arr2[21];
int ret = INF;

void Solution(int x)
{
	
	if (x == n)
	{
		int count{};
		for (int i = 1; i <= 1<<(n-1); i*=2)
		{
			int cnt{};
			for (int j = 0; j < n; j++)
			{
				if (arr2[j] & i)
					cnt++;
			}
			count += min(cnt,n-cnt);
		}
		ret = min(ret, count);

		return;
	}


	Solution(x+1);
	arr2[x] = ~arr2[x];
	Solution(x+1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 1;
		cin >> a;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == 'T')
				arr2[i] |= temp;
			temp *= 2;
		}
	}

	Solution(0);

	cout << ret;
}