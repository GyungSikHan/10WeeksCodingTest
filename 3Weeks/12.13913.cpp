//https://www.acmicpc.net/problem/13913 v
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int arr[200001];
int cnt[200001];
vector<int> v;
queue<int> q;
int ret;
int main()
{
	v.resize(200001, -1);
	cin >> n >> k;

	q.push(n);
	arr[n] = 1;

	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();

		for (int next : {curr - 1, curr + 1, curr * 2})
		{
			if (next < 0 || next > 200000)
				continue;

			if (arr[next] == 0)
			{
				arr[next] = arr[curr] + 1;
				v[next] = curr;
				q.push(next);
			}
		}
	}
	vector<int> ret;
	int temp = k;
	while (temp > -1)
	{
		ret.push_back(temp);
		temp = v[temp];
	}
	cout << arr[k] -1<< endl;
	for (int i = ret.size() - 1; i >= 0; i--)
		cout << ret[i] << " ";
	
}

//BFS�� Ư¡�� ���� �����ؾ߰ڴ� ������ ��� ����
//BFS�� Ư¡�� �����غ��� ������ ����ġ�� ��� ��带 Ž����, ���� ��忡���� ������ ����ġ�� ��� ��带 Ž��
//�� �������� �迭�� �̿��ϸ� ���ϴ� �������� ������ �ֵ��� ��� ��带 ������ �� ����
//arr[next] == 0 �϶�, �� �ش� next�� ���������� ���� �� �ش� ��忡 ������ �ð��� �����ϰ�,queue�� �ش� next�� �����ϴµ� �̶��� �븮�� ���̴�
//v[next] = curr�� ���� �迭�� next��忡 ���� ��� curr�� �����Ѵ�
//�̷��� �Ǹ� �̹� �Դ� ���� Ž������ �����Ƿ� next�� ������ �� � ��忡�� �ִ����� �Դ��� ������ �� �� �ִ�
//���� temp�� k�� �����ϰ�, v[temp]�� �ӽ� �迭�� �����ϰ�, temp�� ���� v[temp]�� �ϴ� ������ temp �� -1���� Ŭ �� ���� �ݺ����ش�
//�̶� temp�� -1���� ū ��쿡�� �ݺ��� �ϴ� ������ ��ġ�� 0������ �� �����Ƿ� v�迭�� -1�� �ʱ�ȭ �߱� �����̴�
//���� �ӽ� ���� �迭 ret�� ������ ������ָ� �ȴ�