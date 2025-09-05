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

//BFS의 특징을 좀더 공부해야겠단 생각이 드는 문제
//BFS의 특징을 생각해보면 동일한 가중치의 모든 노드를 탐색후, 다음 노드에서도 동일한 가중치의 모든 노드를 탐색
//이 과정에서 배열을 이용하면 원하는 지점까지 도착한 애들의 모든 노드를 저장할 수 있음
//arr[next] == 0 일때, 즉 해당 next에 도착한적이 없을 때 해당 노드에 도착한 시간을 저장하고,queue에 해당 next를 저장하는데 이때를 노리는 것이다
//v[next] = curr을 통해 배열의 next노드에 현재 노드 curr을 저장한다
//이렇게 되면 이미 왔던 노드는 탐색하지 않으므로 next에 도착할 때 어떤 노드에서 최단으로 왔는지 저장을 할 수 있다
//이제 temp에 k를 저장하고, v[temp]를 임시 배열에 저장하고, temp의 값을 v[temp]를 하는 과정을 temp 가 -1보다 클 때 까지 반복해준다
//이때 temp가 -1보다 큰 경우에만 반복을 하는 이유는 위치가 0지점일 수 있으므로 v배열을 -1로 초기화 했기 때문이다
//이제 임시 저장 배열 ret을 역순을 출력해주면 된다