//https://www.acmicpc.net/problem/11723
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
const int Max = 21;

int m, k;
string str;
set<int> s;
int temp;
int arr[Max];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str >> k;

		if (str == "add")
			temp |= (1 << k);
		else if (str == "remove")
			temp &= ~(1 << k);
		else if (str == "check")
			cout << ((temp & (1 << k)) ? 1 : 0) << "\n";
		else if (str == "toggle")
			temp ^= 1 << k;
		else if (str == "all")
			temp = (1 << 21) - 1;
		else
			temp = 0;
	}
}

//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> str;
//		if (str == "all")
//			fill(arr, arr + Max, 1);
//		else if (str[0] == 'e')
//			fill(arr, arr + Max, 0);
//		else
//		{
//			cin >> k;
//			if (str[0] == 'a')
//				arr[k] = 1;
//			else if (str[0] == 'r')
//				arr[k] = 0;
//			else if (str[0] == 'c')
//			{
//				cout << arr[k] << "\n";
//			}
//			else if (str[0] == 't')
//			{
//				arr[k] == 1 ? arr[k] = 0 : arr[k] = 1;
//			}
//		}
//	}
//}

