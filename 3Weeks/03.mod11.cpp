#include <iostream>
#include <vector>

using namespace std;

int n, a, ret;
vector<int> v;

void Solution(int index, int sum)
{
	//mod11�̱� ������ �ִ� ���� 10�� ���´�
	//���� 10�� �̹� ã�Ҵٸ� ���̻� ��͸� Ÿ�� �ʾƵ� �ǹǷ� ��Ʈ��ŷ���� �ϴ� ���̴�
	if (ret == 10)
		return;
	if (index == n)
	{
		ret = max(ret, sum % 11);
		return;
	}

	Solution(index + 1, sum + v[index]);
	Solution(index+1, sum);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	Solution(0, 0);

	cout << ret << endl;
}
