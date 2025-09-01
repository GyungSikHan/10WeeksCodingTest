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

//ġ� �쿩�� �Ǵ� ����
//DFS�� �̿��� ġ� �ٷ� ���̵��� Ǯ�������� Ʋ����
//�Ƹ� ġ� �ѷ����� �������� ���õǴ��� ġ�� �Ѹ鿡 �������� 1���� �ƴ� �������� ������ ���� �� ������ ����� �� ��
//�׷��� DFS������ ���� �������� ������ �κ� �� ġ� �ѷ� �׿����� ���� �κе� ��� DFS�� �� �� �ֵ��� while�� �ȿ��� �ݺ��� �� ����
//���� DFS���� ġ� �ٷ� ���̴� ���� �ƴ� ����������, ġ�������� �Ǵ��� ���̰�, �������̸� ��͸�, ġ���� visited�� ���� ��ġ�� true�� �湮ó���� ���ش�
//���� DFS�� ��� ������ Ƚ���� ī��Ʈ���ְ�, Print �Լ����� ���� ũ�⸸ŭ �ݺ����� ���鼭 ���� ��ġ�� visited�� true��� �ǿ��� ġ� �쿩�ش�
//�׷��� �ʴٸ� �ǿ��� ġ���� �κ����� �Ǵ��� ġ���� ���� ī��Ʈ �ϰ�, �Լ��� ������ �� ġ���� ������ return���ش�
// �� ���� temp ������ �������ְ�, temp�� 0�̶�� while���� Ż���ϰ� ġ� �� ���� �ð��� �� ��� �� ������ ġ���� ������ ������ش�
//�̶� ������ ġ���� ������ temp�� Print �Լ��� return���� �����ϱ� �� ret�� temp�� �������־� temp�� 0�϶� ������ ġ���� ������ �̸� �������ش�