// https://www.acmicpc.net/problem/2828 v
#include<iostream>
#include <vector>

using namespace std;

int dx[2]{ -1,1 };
int n, m, j;
vector<int>arr;
vector<bool> visited;
int Count{};
int result = 987654321;

void DFS(int index)
{
	bool b{};
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] == index)
		{
			return;
		}
		else if (arr[i] > index)
			b = true;
		else
			b = false;
	}
	Count++;
	int temp = 1;
	if (b == true)
		temp = -1;
	for (int i = 1; i < arr.size(); i++)
		arr[i] += temp;
	
	DFS(index);
}

int main()
{
	cin >> n >> m;
	cin >> j;
	for (int i = 0; i <= m; i++)
		arr.push_back(i);

	for (int i = 0; i < j; i++)
	{
		int a{};
		cin >> a;

		DFS(a);
	}

	cout << Count << endl;
}

//충분히 풀수있었지만 아이디어싸움에서 진듯..
//보드를 만들고, 바구니를 어떻게 움직여야 될지 아이디어가 마땅한게 떠오르지 않아서 그런듯...
//일단 보드는 없어도 되고, 바구니의 양 끝을 배열에 저장해서 즉 1칸의 바구니면 1만 저장, 2칸의 바구니면 1,2를 저장한뒤
//함수 안에서 반복문을 통해 떨어지는 과일이 바구니 안에 들어오는지 확인 후 들어가지 않으면 현지 위치가 떨어질 위치보다 큰지 작은지 파악
//떨어질 위치보다 크다면 바구니 위치를 전부 -, 작다면 +를 해서 바구니를 이동하면 되는 문제였음