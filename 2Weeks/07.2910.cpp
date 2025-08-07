//https://www.acmicpc.net/problem/2910 v
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, c;
unordered_map<int,int> m,m_num;


bool compare(pair<int,int> a, pair<int,int> b)
{
	if (a.second == b.second)
	{
		return m_num[a.first] < m_num[b.first];
	}
	return a.second > b.second;
}

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		int a{};
		cin >> a;


		m[a]++;
		if (m_num[a] == 0)
		m_num[a] = i;
	}

	vector<pair<int, int>> v(m.begin(),m.end());

	sort(v.begin(), v.end(),compare);
	
	for (const auto& iter : v)
	{
		for (int i = 0; i < iter.second; i++)
			cout << iter.first << " ";
	}
}

//�巴�� �������. ����...�Ф�
//�ؽ� ���̺��� �̿��� Ǫ�� ����
//�ٵ� �ΰ��� map�� �̿��� �ϳ��� ������ ����, �� ���ڰ� ���� ó������ ���������� ����
//map�� sort�� �Ǿ������Ƿ� sort�� �ȵǾ� vector�� ���� �� sort�� �Ұǵ� ���� �� = key, ���� Ƚ�� = value�� ������ �迭 ����
//vector�� sort�� �� compare�� �̿��� ���� Ƚ����ū ������� �����ϸ鼭 ���� Ƚ���� ���ٸ� ���� ó������ ���Դ��� ������ map ���
//�� map�� ���� ���� key�� ���� ���Դ��� ���Ͽ� ���� �͵��� ������ ���� ��
