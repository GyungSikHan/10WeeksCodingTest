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

//�Է¹��� ���� ���ڿ� �����ڸ� ���� ������ �迭�� �������ش�
//���� DFS�� ���� �ִ밪�� ������ ���̴�
//�̶� DFS���� index�� sum�� ���ڷ� �Ѱ��ش�
//�̶� index �� ���ڸ� �������� �迭�� ũ�⺸�� ������ �Լ��� Ż���ϴµ� �̶� ret�� sum�� ���� �ִ밪�� ���� �� Ż���Ѵ�
//���� DFS�� ��͸� Ż���ε� �̶� ������ �� �� �Ѱ��� ���̴�
//������ Oper �Լ����� �Ұ��ε� �� �Լ������� ������ �迭�� ������ ����, �ΰ��� int�� ���� �Ѱ��ش�
//������ �迭�� �Ѱܹ��� ���� ���� '+', '-', '*'�� ������ ���� �� int�� ���� +,-,*�� �ѵ� return���ָ� �ȴ�
//���⼭ return�� ���� ������ DFS�� sum���� �Ѱ��ִµ�, index���� ���� index�� ������ �� �ֵ��� index+1�� �Ѱ��ش�
//�̶� �������� ���Ե��� ������� ����ϴ� ���� �ƴ� ()�� ģ�ٴ� ���� �����غ��� index+2���� n.size-1�� ũ�ų� ������, �� �ڿ� ���� ���� ���� ���ǰ�, sum�� ����� �ǾߵǴµ�
//num�̳� oper�� ũ�⿡ ����� ���� �� �Ǵٸ� DFS�� ������� �Ѵ�
//�̶��� temp�� Oper �Լ��� ���� �����ϴµ� �̶� ���� index+1�� ���� oper�� �ְ�, num[index+1], num[index+2] ���� ������ ���� ���� �����ϴ� ���̴�
//���� DFS �Լ��� ��͸� Ÿ�鼭, index+2��, Oper���� oper[index], sum, temp�� ������ ���� �־��ش�
//�̷��� �Ǹ� DFS�� ���� ��� ����� ���� ������ �ִ밪�� ���� �� �ִ�