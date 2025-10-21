//https://www.acmicpc.net/problem/9935 v
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string s{};
string boom{};
int main()
{
	cin >> s;
	cin >> boom;

	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		st.push(s[i]);

		if (st.size() >= boom.size() && st.top() == boom[boom.size()-1])
		{
			string temp{};
			for (int j = 0; j < boom.size(); j++)
			{
				temp += st.top();
				st.pop();
			}

			reverse(temp.begin(), temp.end());

			if (temp != boom)
				for (int j = 0; j < temp.size(); j++)
					st.push(temp[j]);
		}
	}

	string ret{  };

	if (st.empty() == true)
		cout << "FRULA";
	else
	{
		while (st.empty() == false)
		{
			ret += st.top();
			st.pop();
		}
		reverse(ret.begin(),ret.end());

		cout << ret;
	}
}