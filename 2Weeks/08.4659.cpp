//https://www.acmicpc.net/problem/4659
#include <iostream>
#include  <string>
#include <vector>

using namespace std;

string s;

int main()
{
	while (cin >> s && s != "end")
	{
		char tempC{};
		int count{};
		int count2{};
		int count3{};
		int count4{};
		bool b{};
		for (int i = 0; i < s.size(); i++)
		{
			
			if (tempC == s.at(i))
			{
				count++;
				if ((tempC == 'e' || tempC == 'o') && count < 3)
					continue;
				b = true;
				break;
			}
			else
			{
				tempC = s.at(i);
				count = 1;
				if (tempC == 'a' || tempC == 'e' || tempC == 'i' || tempC == 'o' || tempC == 'u')
				{
					count3 = 0;
					count2++;
					count4++;
				}
				else
				{
					count2 = 0;
					count3++;
				}
				if (count2 >= 3 || count3 >= 3)
				{
					b = true;
					break;
				}
			}
		}
		if (count4 == 0)
			b = true;

		cout << "<" << s;
		if (b == true)
			cout << "> is not acceptable." << endl;
		else
			cout << "> is acceptable." << endl;
	}
}