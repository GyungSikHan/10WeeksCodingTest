#include <iostream>
#include <vector>

using namespace std;

int n, a, ret;
vector<int> v;

void Solution(int index, int sum)
{
	//mod11이기 때문에 최대 값은 10이 나온다
	//따라서 10을 이미 찾았다면 더이상 재귀를 타지 않아도 되므로 백트레킹까지 하는 것이다
	if (ret == 10)
		return;
	if (index == n)
	{
		ret = max(ret, sum % 11);
		return;
	}

	Solution(index + 1, sum + v[index]);
	Solution(index+1, sum);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	Solution(0, 0);

	cout << ret << endl;
}
