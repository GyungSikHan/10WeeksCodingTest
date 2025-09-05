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

//n에서 k까지 가는데 이동은 -1, +1, *2를 한 칸으로 이동하는 것이다
//가중치는 같기 때문에 BFS를 떠올려 풀어야 한다
//이전까지는 4방향으로 움직이는 것을 풀었지만 이 문제는 2방향으로 이동을 한다
//이때 중요한 것은 arr[next]가 0일때 arr[next] = arr[curr] +1을 해 이동 시간을 누적한 값을 arr[next]에 저장한다
//또한 해당 index에 가는 방법을 cnt[next]에 cnt[curr]를 더한 값을 cnt[next]에 더해준다
//만약 arr[next]가 0이 아니지만 arr[curr]+1과 같을때, 즉 동일한 시간이 걸리지만 다른 방법으로 도착했을 때를 생각해봐야한다
//이때는 cnt[next]에 cnt[curr]를 더해 cnt[next]에 저장해준다
//이렇게 되면 curr를 간 방법에 next에 도착한 애들을 더해 최소 시간으로 next에 도착한 것들을 모두 샐 수 있다
//BFS를 이용해 현재 위치에서 이동하는 모든 방법을 확인하기 때문에 가능하다