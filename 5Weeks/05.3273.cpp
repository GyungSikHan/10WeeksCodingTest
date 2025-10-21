//https://www.acmicpc.net/problem/3273
#include <algorithm>
#include <iostream>

using namespace std;

int n, a, x;
int arr[1000001];
int l, r;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> x;
	r = n - 1;

	sort(arr, arr + n);

	int count{};
	while (l < r)
	{
		if (arr[l] + arr[r] == x)
		{
			count++;
			l++;
			r--;
		}
		else if (arr[l] + arr[r] > x)
			r--;
		else if (arr[l] + arr[r] < x)
			l++;
	}

	cout << count;
}
