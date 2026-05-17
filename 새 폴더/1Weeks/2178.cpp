#include <bits/stdc++.h>

using namespace std;

int dx[4]{-1, 0, 1, 0}, dy[4]{0, -1, 0, 1};

int n, m;
int arr[100][100];
int visited[100][100];
int ret;
string s;

void BFS()
{
    queue<pair<int, int>> qu;
    qu.push({0, 0});

    while (qu.empty() == false)
    {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        //cout << x << " " << y << endl;

        if (x + 1 == n && y + 1 == m)
        {
            //cout << "end" << endl;
            ret = visited[x][y];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // cout<<nx<<" "<<ny<<endl<<endl;
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         cout << visited[i][j];
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 1)
            {
                //cout << "if 1" << endl;
                if(visited[nx][ny] != 0)
                {
                    //cout << "false" << endl;
                    continue;
                }
                // cout<<"true"<<endl;
                visited[nx][ny] = visited[x][y] + 1;
                qu.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            arr[i][j] = s.at(j) - '0';
        }
    }
    visited[0][0] = 1;

    BFS();

    cout << ret;
}