#include <iostream>
#include <vector>

using namespace std;

int n, a;
vector<int> arr;

int Check(int data)
{
	if (data <= 1)
		return 0;
	else if (data == 2)
		return 1;
	else if (data % 2 == 0)
		return 0;

	//�Ҽ��� ���� �� data�� i*i�� ���ϴ� ������ data�� ��������� ���� �ȴ�
	//���� ��� 36�̶�� ���� ����
	//��������� 1,2,3,4,6,9,12,18,36�� �ִ�
	//�̵��� ����� ������ ����� (1,36) (2,18) (3,12) (4,9) (6,6)�̴�
	//i�� ��� ���ϴ� ���� �ƴ� ����� ���� ���� ���� ū ���� ����� �����Ƿ� ���� ���鸸 ���ϸ�
	//���귮�� ũ�� ���� �� �ִ�
	for (int i = 3; i * i <= data; i++)
		if (data % i == 0)
			return 0;

	return 1;
}

int Solution(int index, int sum)
{
	if (count == n)
		return Check(sum);

	return Solution(index + 1, sum + arr[index]) + Solution(index + 1, sum);
}

int main()
{
	cin >> n;
	arr.assign(n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		
		arr[i] = a;
	}

	int num{};
	Solution(0,0);

	cout << num << endl;
}