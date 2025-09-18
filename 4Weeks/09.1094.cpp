//https://www.acmicpc.net/problem/1094
#include <iostream>
#include <vector>

using namespace std;

//해설
int x, result = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr)
	cin >> x;
	while (x != 1)
	{
		if ((x & 1) == 1)
			result++;
		x /= 2;
	}
	cout << result;
}

//내가 푼 방법
//int x, stick = 64, cnt;
//
//int main()
//{
//	cin >> x;
//
//	if (x == 64)
//	{
//		cout << 1;
//		return 0;
//	}
//
//	vector<int> v;
//	v.push_back(stick);
//	while (true)
//	{
//		int half = v.back();
//		if (x == half)
//			break;
//
//		v.pop_back();
//		half /= 2;
//		int sum = half;
//		for (int i : v)
//			sum += i;
//
//		if (sum >= x)
//		{
//			v.push_back(half);
//			if (sum == x)
//				break;
//		}
//		else
//		{
//			v.push_back(half);
//			v.push_back(half);
//		}
//	}
//
//	cout << v.size();
//}