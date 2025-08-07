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

//����� Ǯ���־����� ���̵��ο򿡼� ����..
//���带 �����, �ٱ��ϸ� ��� �������� ���� ���̵� �����Ѱ� �������� �ʾƼ� �׷���...
//�ϴ� ����� ��� �ǰ�, �ٱ����� �� ���� �迭�� �����ؼ� �� 1ĭ�� �ٱ��ϸ� 1�� ����, 2ĭ�� �ٱ��ϸ� 1,2�� �����ѵ�
//�Լ� �ȿ��� �ݺ����� ���� �������� ������ �ٱ��� �ȿ� �������� Ȯ�� �� ���� ������ ���� ��ġ�� ������ ��ġ���� ū�� ������ �ľ�
//������ ��ġ���� ũ�ٸ� �ٱ��� ��ġ�� ���� -, �۴ٸ� +�� �ؼ� �ٱ��ϸ� �̵��ϸ� �Ǵ� ��������