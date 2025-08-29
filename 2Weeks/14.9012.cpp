//https://www.acmicpc.net/problem/9012
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int t;
string c;

//stack 사용 문제풀이
string Solution(stack<char>& st)
{
	for (int i = 0; i < c.size(); i++)
	{
		if (c.at(i) == '(')
			st.push(c.at(i));
		else
		{
			if (st.empty() == true)
				return "NO";
			st.pop();
		}
	}

	if (st.empty() == true)
		return "YES";
	return "NO";
}

//vector 사용 문제풀이
string Solution(vector<char>& v)
{
	int index{};
	for (int i = 0; i < c.size(); i++)
	{
		if (v.empty() == true )
		{
			if (c.at(i) == ')')
				return "NO";
			v.push_back(c.at(i));
			index++;
		}
		else
		{
			if (v[index-1] == c.at(i))
			{
				v.push_back(c.at(i));
				index++;
			}
			else
			{
				v.pop_back();
				index--;
			}
		}
	}

	string ret{};
	if (v.empty() == false)
		ret = "NO";
	else
		ret = "YES";

	return ret;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<char> v;
		stack<char> st;
		cin >> c;
		cout << Solution(st) << endl;
	}
}