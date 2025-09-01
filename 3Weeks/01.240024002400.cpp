#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n{};
	cin >> n;
	string s = "2400";
	int data = 2400;

	int index = 1;
	while (n != index)
	{
		s = std::to_string((stoi(s) + 1));
		if (s.find("2400") != s.npos)
			index++;
	}

	cout << s << endl;
}