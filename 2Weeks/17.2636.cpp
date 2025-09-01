//https://www.acmicpc.net/problem/2636 v
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<vector<int>> board;
vector<vector<bool>> visited;
int n, m, times, ret;

int Print()
{	int count{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == true)
				board[i][j] = 0;
			if (board[i][j] == 1)
				count++;
		}
	}
	return count;
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (visited[nx][ny] == false)
		{
			if (board[nx][ny] == 1)
				visited[nx][ny] = true;
			else
				DFS(nx,ny);
		}
	}
}

int main()
{
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
		
	int temp{};
	while (true)
	{
		ret = temp;
		temp = Print();
		if (temp == 0)
			break;
		visited.assign(n, vector<bool>(m, false));
		DFS(0,0);
		times++;
	}

	cout << times << endl;
	cout << ret << endl;
}

//치즈를 녹여야 되는 문제
//DFS를 이용해 치즈를 바로 녹이도록 풀었엇지만 틀렸음
//아마 치즈에 둘러쌓인 공기층이 무시되더라도 치즈 겉면에 공기층이 1개가 아닌 여러개로 나눠져 있을 때 문제가 생기는 듯 함
//그래서 DFS에서는 현재 공기층에 접촉한 부분 중 치즈에 둘러 쌓여있지 않은 부분들 모두 DFS에 돌 수 있도록 while문 안에서 반복을 할 것임
//또한 DFS에서 치즈를 바로 녹이는 것이 아닌 공기층인지, 치즈인지만 판단할 것이고, 공기층이면 재귀를, 치즈라면 visited의 현재 위치를 true로 방문처리를 해준다
//이후 DFS가 모두 끝나면 횟수를 카운트해주고, Print 함수에서 판의 크기만큼 반복문을 돌면서 현재 위치의 visited가 true라면 판에서 치즈를 녹여준다
//그렇지 않다면 판에서 치즈인 부분인지 판단해 치즈의 수를 카운트 하고, 함수가 끝나면 총 치즈의 갯수를 return해준다
// 이 값을 temp 변수에 저장해주고, temp가 0이라면 while문을 탈출하고 치즈가 다 녹은 시간과 다 녹기 전 마지막 치즈의 갯수를 출력해준다
//이때 마지막 치즈의 갯수는 temp에 Print 함수의 return값을 저장하기 전 ret에 temp를 저장해주어 temp가 0일때 마지막 치즈의 갯수를 미리 저장해준다