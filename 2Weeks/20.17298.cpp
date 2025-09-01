//https://www.acmicpc.net/problem/17298 v

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> A;
vector<int>ret;
stack<int> st;
int main()
{
	cin >> n;
	A.assign(n,0);
	ret.assign(n,-1);
	
	for (int i = 0; i < n; i++)
	{
		int a{};
		cin >> a;
		A[i] = a;

		while (st.empty() == false && A[i] > A[st.top()])
		{
			ret[st.top()] = A[i];
			st.pop();
		}

		st.push(i);
	}


	for (int iter : ret)
		cout << iter << " ";

}