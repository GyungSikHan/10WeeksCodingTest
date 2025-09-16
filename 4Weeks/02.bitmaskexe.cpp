#include <iostream>

using namespace std;

const int n = 4;
string a[4]{ "사과", "딸기", "포도", "배" };

void Go(int num)
{
	string ret{};
	for (int i = 0; i < n; i++)
	{
		if (num & (1 << i))
			ret += a[i] + " ";
	}
	cout << ret << endl;
}

int main()
{
	for (int i = 1; i < n; i++)
		Go(1 | (1<<i));
}