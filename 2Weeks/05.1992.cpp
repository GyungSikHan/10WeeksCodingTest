//https://www.acmicpc.net/problem/1992 v
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
int n;
vector<vector<char>> board;

string Solution(int size, int y, int x)
{
	if (size == 1)
		return string(1,board[y][x]);
	char temp = board[y][x];
	string s{};
	for (int i = y; i < y+size; i++)
	{
		for (int j = x; j < x+size; j++)
		{
			if (temp != board[i][j])
			{
				int tempSize = size / 2;
				s += '(';
				s += Solution(tempSize, y, x);
				s += Solution(tempSize,y,x+tempSize);
				s += Solution(tempSize,y + tempSize,x);
				s += Solution(tempSize,y+tempSize,x+tempSize);
				s += ')';
				return s;
			}
		}
	}

	return string(1,board[y][x]);
}

int main()
{
	cin >> n;
	board.assign(n, vector<char>(n, 0));
	for (int i = 0; i < n; i++)
	{
		string s{};
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			board[i][j] = s.at(j);
		}
	}

	cout<<Solution(n,0,0);
}

//���� ������ �̿��ϴ� ����
//���� �� Ǯ������ ��ƽ�� �ƽ����� ������ ������ ���ߴ�
//�ϴ� ��� �Լ��� �� �� size/2�� �ϴ°� ������ �ߴµ� x,y���� ��� ó���ؾߵ��� ������ ������ ���� �ʾҰ�,
//Ż�� �����̳� ���� ���� ������ �� ��� ó������ ������ ���ϰ� �־���