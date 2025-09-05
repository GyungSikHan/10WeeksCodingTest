//https://www.acmicpc.net/problem/16637 v
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
char c;
vector<int> num;
vector<char> op;
int ret = -987654321;

int Oper(int oper, int num, int num2)
{
	if (oper == '+')
		return num + num2;
	else if (oper == '-')
		return num - num2;
	return num * num2;
}

void DFS(int index, int sum)
{
	if (index == num.size()-1 )
	{
		ret = max(ret, sum);
		return;
	}

	DFS(index + 1, Oper(op[index], sum, num[index + 1]));
	if (index+2<= num.size()-1)
	{
		int temp = Oper(op[index + 1], num[index + 1], num[index + 2]);
		DFS(index+2, Oper(op[index], sum, temp));
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c >= '0' && c <= '9')
			num.push_back(c - '0');
		else
			op.push_back(c);
	}

	DFS(0,num[0]);
	cout << ret << endl;
}

//입력받은 값을 숫자와 연산자를 따로 각각의 배열에 저장해준다
//이후 DFS를 통해 최대값을 구해줄 것이다
//이때 DFS에는 index와 sum을 인자로 넘겨준다
//이때 index 가 숫자를 저장해준 배열의 크기보다 작으면 함수를 탈출하는데 이때 ret과 sum을 비교해 최대값을 비교한 뒤 탈출한다
//이후 DFS를 재귀를 탈것인데 이때 연산을 한 뒤 넘겨줄 것이다
//연산은 Oper 함수에서 할것인데 이 함수에서는 연산자 배열에 저장한 값과, 두개의 int형 값을 넘겨준다
//연산자 배열에 넘겨받은 값에 따라 '+', '-', '*'와 같으면 각각 두 int형 값을 +,-,*을 한뒤 return해주면 된다
//여기서 return된 값을 가지고 DFS에 sum으로 넘겨주는데, index에는 다음 index에 접근할 수 있도록 index+1을 넘겨준다
//이때 문제에서 나왔듯이 순서대로 계산하는 것이 아닌 ()를 친다는 것을 가정해보면 index+2보다 n.size-1이 크거나 같으면, 즉 뒤에 오는 값이 먼저 계산되고, sum과 계산이 되야되는데
//num이나 oper의 크기에 벗어나지 않을 때 또다른 DFS를 돌아줘야 한다
//이때는 temp에 Oper 함수의 값을 저장하는데 이때 현재 index+1한 값을 oper에 넣고, num[index+1], num[index+2] 값의 연산을 해준 값을 저장하는 것이다
//이후 DFS 함수로 재귀를 타면서, index+2를, Oper에는 oper[index], sum, temp를 연산한 값을 넣어준다
//이렇게 되면 DFS를 통해 모든 경우의 수를 연산해 최대값을 구할 수 있다