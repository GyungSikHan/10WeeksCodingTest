//https://www.acmicpc.net/problem/15686 v
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4]{ -1,0,1,0 }, dy[4]{ 0,-1,0,1 };

int n, m, map[54][54], result = 987654321;
vector<vector<int>> chickenList;
vector<pair<int, int>> homes, chickens;

void Combi(int start, vector<int> v)
{
	if (v.size() == m)
	{
		chickenList.push_back(v);
		return;
	}

	for (int i = start+1; i < chickens.size(); i++)
	{
		v.push_back(i);
		Combi(i,v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				homes.push_back({i,j});
			else if (map[i][j] == 2)
				chickens.push_back({i,j});
		}
	}

	vector<int>v;
	Combi(-1, v);

	for (vector<int> cList : chickenList)
	{
		int ret{};
		for (auto home : homes)
		{
			int mins = 987654321;
			for (int ch : cList)
			{
				int dist = abs(home.first - chickens[ch].first) + abs(home.second - chickens[ch].second);
				mins = min(mins,dist);
			}
			ret += mins;
		}

		result = min(result, ret);
	}

	cout << result;
}

//시간복잡도를 구하는 방법에 대해 좀더 공부해야될듯...
//일단 무식하게 풀면 최악의 경우 모든 도시가 치킨집이고 m개를 선택한다 하면 n*nCm이다
//하지만 조건에 나와있듯이 집의 최대 갯수는 2N개이고, 치킨집의 갯수는 m보다 크거나 같지만 13보다는 작다
//이를 이용하면 13Cm이 최대 치킨집중 m개의 치킨집을 선택할 수 있는 조합의 갯수를 구할 수 있다
//구한 조합의 개수에 2n을 곱해 각 경우마다 집과 치킨집 사이의 거리를 최악의 상황에서 구한 것이다
//마지막으로 m을 또 곱해 각 집에서 선택된 m개의 치킨집 중 가장 가까운 곳을 찾기위해 m 번 비교하는 것이다
//따라서 최악의 시간 복잡도는 13Cm*2n*m이다
//이때 조합의 성질을 이용하면 중간에 있는 m 값이 가장 큰 값이 나오기 때문에 13의 절반인 6이나 7을 m에 넣으면 최악의 시간 복잡도를 구할 수 있다
//이를통해 값을 구해보면 13C6*2*50*6 = 13!/6!(13-6)! * 2*50 * 6 = 1716 * 100 * 6 = 1029600, 13C7*2*50*7 = 1,201,200
//두 값 모두 시간 제한 안에 풀기 충분하므로 무식하게 풀어도 된다

//여기서 조합이므로 Combi 함수를 사용해 줘야한다
//먼저 치킨집과, 집의 위치를 저장할 배열에 x,y를 저장해주고, Combi 함수를 호출한다

//외워두기
//Combi(int start, vector<>v)
//{
//	if (v.size() == m)
//	{
//		List.push_back(v);
//		return;
//	}
//
//	for (int i = start + 1; i < 구하고자하는값의 크기; i++)
//	{
//		v.push_back(i);
//		Combi(i, v);
//		v.pop_back();
//	}
//}

//Combi함수에서는 배열의 크기가 m의 크기와 같으면 list에 배열을 저장해주고, 그렇지 않으면 start+1부터 구하고자하는값의 크기, 즉 여기서는 치킨집들의 위치를 저장한 배열의 크기
//만큼 for문을 돌면서 v에 i를 넣고, Combi함수를 호출해고, Combi함수를 탈출하면 다시 pop을 하는 식으로 조합을 만든다

//이제 3중 for문일 이용해 처음엔 치킨집 리스트들, 두번째에는 모든 집들, 세번째는 치킨집 리스트에 저장된 값을 이용해 for문을 돈다
//여기서 집의 위치 x,y와 치킨집 리스트에 저장된 값을 index로 구한 치킨집 위치를 빼준 뒤 제곱을 하여 구한 x,y 값을 더한다
//이러면 현재 집과, 치킨집 사이의 거리를 구할 수 있다.
//이후 구한 거리와, 이전에 최소 거리를 비고해 작은 값을 구해준다
//치킨집 리스트에 저장된 값으로 도는 반복문이 끝나면 최소 거리를 임시 변수에 누적해 더해준다
//이렇게 되면 임시 변수에는 m개의 치킨집에서 집들의 최소 거리를 더한 값이 저장되있을 것이다
//이후 집에대한 반복문이 끝나면 result 변수에 result와 임시변수를 비교해 작은 값을 저장해준다
//이러면 result에 모든 조합에서 가장 작은 거리를 구할 수 있다