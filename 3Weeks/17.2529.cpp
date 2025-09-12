//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
char arr[10];
int nums[10];
unsigned long long mx;
unsigned long long mi = INTMAX_MAX;
bool Check(int index, int data, int data2)
{
	if (arr[index] == '<')
		return data < data2;

	return data > data2;
}

void DFS(int index, unsigned long long data, int prev)
{
	if (index == k)
	{
		mx = max(mx,data);
		mi=min(mi,data);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == prev)
			continue;
		if (nums[i] != 0)
			continue;
		if (Check(index, prev, i) == false)
			continue;

		nums[i] = 1;
		DFS(index + 1, data*10+i, i);
		nums[i] = 0;
	}
}

int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 10; i++)
	{
		nums[i] = 1;
		DFS(0,i, i);
		nums[i] = 0;
	}

	string temp = to_string(mx);
	string temp2 = to_string(mi);
	if (temp.size() < k + 1)
		temp = "0" + temp;
	if (temp2.size() < k + 1)
		temp2 = "0" + temp2;

	cout << temp << endl;
	cout << temp2 << endl;
}