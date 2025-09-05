//https://www.acmicpc.net/problem/12851 v

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int arr[100001];
int cnt[100001];
queue<int> q;

int main()
{
	cin >> n >> k;

	q.push(n);
	arr[n] = 1;
	cnt[n] = 1;

	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();
		//cout << curr << endl;
		for (int next : {curr -1, curr+1, curr*2})
		{
			if (next < 0 || next > 100000)
				continue;
			if (arr[next] == 0)
			{
				arr[next] = arr[curr] + 1;
				cnt[next] += cnt[curr];
				q.push(next);
			}
			else if (arr[next] == arr[curr]+1)
				cnt[next] += cnt[curr];
		}
	}
	cout << arr[k]-1 << endl;
	cout << cnt[k] << endl;
}

//n���� k���� ���µ� �̵��� -1, +1, *2�� �� ĭ���� �̵��ϴ� ���̴�
//����ġ�� ���� ������ BFS�� ���÷� Ǯ��� �Ѵ�
//���������� 4�������� �����̴� ���� Ǯ������ �� ������ 2�������� �̵��� �Ѵ�
//�̶� �߿��� ���� arr[next]�� 0�϶� arr[next] = arr[curr] +1�� �� �̵� �ð��� ������ ���� arr[next]�� �����Ѵ�
//���� �ش� index�� ���� ����� cnt[next]�� cnt[curr]�� ���� ���� cnt[next]�� �����ش�
//���� arr[next]�� 0�� �ƴ����� arr[curr]+1�� ������, �� ������ �ð��� �ɸ����� �ٸ� ������� �������� ���� �����غ����Ѵ�
//�̶��� cnt[next]�� cnt[curr]�� ���� cnt[next]�� �������ش�
//�̷��� �Ǹ� curr�� �� ����� next�� ������ �ֵ��� ���� �ּ� �ð����� next�� ������ �͵��� ��� �� �� �ִ�
//BFS�� �̿��� ���� ��ġ���� �̵��ϴ� ��� ����� Ȯ���ϱ� ������ �����ϴ�