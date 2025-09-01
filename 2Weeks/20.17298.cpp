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

//짝짓기 문제는 거의 항상 Stack을 이용해서 풀면 된다
//Stack을 어떻게 이용할거냐...
//일단 입력받은 수를 배열에 저장해놓고, stack이 비어있거나, 오큰수를 찾지 못하면 stack에 현재 index를 담아놓는다
//그 후 다음 숫자를 입력받고, 똑같은 것을 반복하는데, 이때 오큰수를 찾았다면 stack의 top을 꺼내 index로 사용하면서 오큰수를 저장하는 배열에 현재 들어온 값을 저장한다
//오큰수를 저장하는 배열을 -1로 초기화 하였으므로, 반복문이 끝났을때까지 오큰수를 찾지 못했으면 자연스럽게 -1이 들어갈 것이다