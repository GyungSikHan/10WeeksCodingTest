#include <iostream>

using namespace std;

int main()
{
	const int n = 4;

	string a[n]
	{
		"���","����","����","��"
	};

	for (int i = 1; i <(1<<n); i++)
	{
		string ret{};
		for (int j = 0; j < n; j++)
		{
			if (i & (1<<j))
				ret+=(a[j]+" ");
		}
		cout << ret << endl;
	}
}
