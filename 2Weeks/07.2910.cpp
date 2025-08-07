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

//드럽게 어려웠다. 왜지...ㅠㅠ
//해시 태이블을 이용해 푸는 문제
//근데 두개의 map을 이용해 하나는 숫자의 갯수, 그 숫자가 언제 처음으로 들어오는지를 저장
//map은 sort가 되어있으므로 sort가 안되어 vector에 저장 후 sort를 할건데 들어온 수 = key, 들어온 횟수 = value를 저장할 배열 만듦
//vector를 sort할 때 compare를 이용해 들어온 횟수가큰 순서대로 정렬하면서 들어온 횟수가 같다면 언제 처음으로 들어왔는지 저장한 map 사용
//이 map에 들어온 수를 key로 언제 들어왔는지 비교하여 작은 것들을 앞으로 빼면 됨
