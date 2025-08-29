//https://www.acmicpc.net/problem/4949
#include <iostream>
#include <string>
#include  <vector>
#include <stack>
using namespace std;

string s;

//Vector 를 이용한 문제풀이
void Solution(vector<char> smal, vector<char> middle)
{
	stack<char> st;
	int index1{}, index2{};
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) != '(' && s.at(i) != ')' && s.at(i) != '[' && s.at(i) != ']')
			continue;

		if (st.empty() == false && st.top() == '(')
		{
			if (s.at(i) == ']')
			{
				cout << "no" << endl;
				return;
			}
		}
		else if (st.empty() == false && st.top() == '[')
		{
			if (s.at(i) == ')')
			{
				cout << "no" << endl;
				return;
			}
		}

		if (s.at(i) == '(' || s.at(i) == ')')
		{
			if (smal.empty() == true)
			{
				if (s.at(i) == ')')
				{
					cout << "no" << endl;
					return;
				}
				smal.push_back(s.at(i));
				index1++;
				st.push(s.at(i));
			}
			else
			{
				if (smal[index1-1] == s.at(i))
				{
					smal.push_back(s.at(i));
					st.push(s.at(i));
					index1++;
				}
				else
				{
					smal.pop_back();
					st.pop();
					index1--;
				}
			}
		}
		else
		{
			if (middle.empty() == true)
			{
				if (s.at(i) == ']')
				{
					cout << "no" << endl;
					return;
				}
				middle.push_back(s.at(i));
				index2++;
				st.push(s.at(i));
			}
			else
			{
				if (middle[index2 - 1] == s.at(i))
				{
					middle.push_back(s.at(i));
					index2++;
					st.push(s.at(i));
				}
				else
				{
					middle.pop_back();
					index2--;
					st.pop();
				}
			}
		}
	}
	if (smal.empty() == false || middle.empty() == false)
		cout << "no" << endl;
	else
		cout << "yes" << endl;
}

//Stack을 이용한 문제풀이
void Solution(stack<char> st)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) != '(' && s.at(i) != ')' && s.at(i) != '[' && s.at(i) != ']')
			continue;
		else if (s.at(i) == ')')
		{
			if (st.empty() == true || st.top() == '[')
			{
				cout << "no" << endl;
				return;
			}
			st.pop();
		}
		else if (s.at(i) == ']')
		{
			if (st.empty() == true || st.top() == '(')
			{
				cout << "no" << endl;
				return;
			}
			st.pop();
		}
		else
			st.push(s.at(i));
	}
	if (st.empty() == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main()
{
	while (getline(cin,s,'.'))
	{
		if (s == "\n")
			break;
		//Vector 사용
		{
			//vector<char> smal, middle;
			//Solution(smal,middle);
		}
		//Stack 사용
		{
			stack<char> st;
			Solution(st);
		}
	}
	
}