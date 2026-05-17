#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int n, ret = 1;
int a= -1, b = 987654321;
int arr[101][101];
int visited[101][101];
int visited2[101][101];

void DFS(int y, int x, int data)
{
    for(int i = 0; i< 4; i++)
    {
        int ny = dy[i]+y;
        int nx = dx[i]+x;

        if(ny < 0 || ny>=n || nx < 0||nx >=n)
            continue;
        if(visited[ny][nx] == 1 || arr[ny][nx] <= data)
            continue;
        
        visited[ny][nx] = 1;
        DFS(ny,nx,data);
    }
}

void Solution(int data)
{
    int temp{};
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j] > data && visited[i][j] == 0)
            {
                temp++;
                DFS(i,j, data);
            }
        }
    }

    ret = max(ret, temp);

}

int main()
{
    cin>>n;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>arr[i][j];
            a = max(a, arr[i][j]);
            b = min(b,arr[i][j]);
        }
    }

    for(int i = b; i < a; i++)
    {
        memset(visited, 0, sizeof(visited));
        Solution(i);
    }

    cout<<ret;
}