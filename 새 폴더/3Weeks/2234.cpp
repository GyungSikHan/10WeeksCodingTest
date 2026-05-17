#include <bits/stdc++.h>

using namespace std;
int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int n, m, ret1, ret2 = -1, ret3 = -1;
vector<vector<int>> ma;
vector<vector<int>> visited;
vector<vector<int>>visited2;
vector<int> v;
vector<int> v2;
void Print()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int DFS(int y, int x, const int& team)
{
    visited[y][x] = team;
    //Print();
    int sum = 1;
    for(int i = 0; i<4 ; i++)
    {
        if((ma[y][x] & (1<<i)) == 0)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(visited[ny][nx] == 0)
                sum += DFS(ny,nx, team);
        }
    }

    return sum;
}

void BFS(int y, int x)
{
    queue<pair<int, int>>qu;
    qu.push({y,x});
    visited2[y][x] = 1;
    vector<int> temp = v;
    while(qu.empty() == false)
    {
        int curry = qu.front().first;
        int cyrrx = qu.front().second;
        qu.pop();
        for(int i = 0; i<4; i++)
        {
            int ny = curry+dy[i];
            int nx = cyrrx+dx[i];
            if(ny<0||m <= ny || nx<0||n<= nx)
                continue;
            if(visited2[ny][nx] == 1)
                continue;
            if(visited[ny][nx] == visited[y][x])
            {
                qu.push({ny,nx});
                visited2[ny][nx] = 1;
            }
            else
            {
                if(temp[visited[ny][nx]] == 1)
                    continue;

                temp[visited[ny][nx]] = 1;
                ret3 = max(ret3, v2[visited[y][x]-1] + v2[visited[ny][nx]-1]);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    ma.resize(m, vector<int>(n, 0));
    visited.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ma[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                int temp{};
                ret1++;
                //cout<<ret1<<endl;
                temp = DFS(i, j, ret1);
                v2.push_back(temp);
                ret2 = max(ret2, temp);
            }
        }
    }

    v.resize(ret1+1, 0);
    visited2.resize(m,vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(visited2[i][j] == 0)
            {
                v[visited[i][j]] = 1;
                BFS(i,j);
            }
        }
    }
    cout << ret1 << "\n";
    cout << ret2 << "\n";
    cout <<ret3<<"\n";
}