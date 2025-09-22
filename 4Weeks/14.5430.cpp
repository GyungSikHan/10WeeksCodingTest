#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int t, n;
string p,s;



int main()
{
	cin >> t;
	while (t > 0)
	{
		cin >> p;
		cin >> n;
		cin >> s;
		deque<string> v;
		int index{};
		string temp{};
		for (int i = 1; i < s.size()-1; i++)
		{
			if (s[i] == ',')
			{
				v.insert(v.begin() + index++, temp);
				temp = {};
			}
			else
				temp += s[i];
		}
		if (temp.empty() == false)
			v.insert(v.begin()+index,temp);

		bool rev{};
		bool ret{};
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
				rev = !rev;
			else
			{
				if (v.empty() == true)
				{
					ret = true;
					break;
				}
				else if (rev == false)
					v.pop_front();
				else if (rev == true)
					v.pop_back();
			}
		}
		vector<int> result;
		index = 0;
		if (ret == true)
			cout << "error\n";
		else
		{
			if (rev == true)
			{
				for (auto i = v.rbegin(); i != v.rend(); i++)
				{
					result.push_back(stoi(*i));
				}
			}
			else
			{
				for (auto c : v)
					result.push_back(stoi(c));
			}

			cout << "[";
			for (int i = 0; i < v.size(); i++)
			{
				cout << result[i];
				if (i != v.size() - 1)
					cout << ",";
			}
			cout << "]\n";
		}
		t--;
	}
}