#include <iostream>
#include <vector>

using namespace std;

string s;
string arr[3]{ "pi","ka", "chu" };

int main()
{
	cin >> s;

	int size = s.size();
	bool b{};
	while (b == false && s.empty() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			if (s.at(0) == arr[i].at(0))
			{
				b = false;
				s = s.substr(arr[i].size());
				break;
			}
			else
				b = true;
		}
	}

	if (b == true)
		cout << "NO";
	else
		cout << "YES";
}