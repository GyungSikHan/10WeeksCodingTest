#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, temp, ret;
char c;
stack<char>st;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;

		if (st.empty() == true || st.top() == c)
		{
			if (c == ')')
			{
				ret = max(ret,temp);
				temp = 0;
				continue;
			}
			st.push(c);
		}
		else
		{
			st.pop();
			temp+=2;
		}
	}
	ret = max(ret, temp);
	cout << ret;
}