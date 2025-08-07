//https://www.acmicpc.net/problem/2870

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string s;
vector<string> v;

bool compare(string a, string b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a.at(i) != b.at(i))
				return a.at(i) < b.at(i);
		}
	}

	return a.size() < b.size();
}

void Solution()
{
	string temp{};
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) >= '0' && s.at(i) <= '9')
		{
			if (temp != "" && temp == "0")
				temp = "";
			temp += s.at(i);
		}
		else
		{
			if (temp != "")
				v.push_back(temp);
			
			temp = "";
		}
	}

	if (temp != "")
		v.push_back(temp);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		Solution();
	}

	sort(v.begin(), v.end(), compare);
	for (const auto& iter : v)
		cout << iter << endl;
}