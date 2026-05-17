#include <bits/stdc++.h>

using namespace std;

int dy[4]{0, -1, 0, 1}, dx[4]{-1, 0, 1, 0};
int r, c, ret;
int a;
char arr[21][21];

void DFS(int y, int x, int cnt)
{
    for (int i = 0; i < 4; i++)
    {
        int ny =dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || r <= ny || nx < 0 || c <= nx)
            continue;
        int as = (1 << (arr[ny][nx] - 'A'));
        if ((a & as) == 0)
        {
            a |= as;
            DFS(ny, nx, cnt + 1);
            a &= ~as;
        }
    }
    ret = max(ret, cnt);
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    a |= (1 << (arr[0][0] - 'a'));

    DFS(0, 0, 1);

    cout << ret;
}