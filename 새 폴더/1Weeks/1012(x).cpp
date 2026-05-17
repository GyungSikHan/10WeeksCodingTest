#include <bits/stdc++.h>

using namespace std;

int dx[4]{-1, 0, 1, 0}, dy[4]{0, -1, 0, 1};
int t, n, m, k;
int arr[54][54];
int visited[54][54];
int ret;
int a, b;

void DFS(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0||nx>=m||ny<0||ny>=n)
            continue;
        if(arr[nx][ny] == 0)
            continue;
        if(visited[nx][ny] == 1)
            continue;

        cout<<nx<<" "<<ny<<endl;
        visited[nx][ny] = 1;
        DFS(nx,ny);
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> k;
        ret = 0;
        memset(&arr[0][0],0, sizeof(arr));
        memset(&visited[0][0], 0, sizeof(visited));

        for(int j = 0; j < k; j++)
        {
            cin>>a>>b;
            arr[a][b] = 1;
        }

        for (int j = 0; j < m; j++)
        {
            for (int h = 0; h < n; h++)
            {
                if(arr[j][h] == 1 && visited[j][h] == 0)
                {
                    ret++;
                    visited[j][h] = 1;
                    DFS(j,h);
                }
            }
        }
        cout<<ret<<"\n";

        
    }
}