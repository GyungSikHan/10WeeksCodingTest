//x
#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};

int r,c,ret = 1;
char arr[21][21];
int eng[26];

void DFS(int y, int x, int count)
{    
    for(int i = 0;i<4;i++)
    {
        int ny = dy[i]+y;
        int nx= dx[i]+x;

        if(ny<0||ny>=r||nx<0||nx >=c)
            continue;
        if(eng[arr[ny][nx] - 'A'] != 0)
        {
            ret = max(ret, count);
            continue;
        }

        eng[arr[ny][nx] - 'A'] = 1;
        DFS(ny,nx,count+1);
        eng[arr[ny][nx] - 'A'] = 0;
    }
}

int main()
{
    cin>>r>>c;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    eng[arr[0][0] - 'A'] = 1;
    DFS(0,0,1);

    cout<<ret;
}