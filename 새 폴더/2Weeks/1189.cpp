#include<bits/stdc++.h>

using namespace std; 

int dy[4] {0,-1,0,1}, dx[4]{-1,0,1,0};

int r,c,k;
char arr[6][6];
int visited[6][6];
int ret;

void Print()
{
    cout<<endl;
    for(int i = 0; i< r; i++)
    {
        for(int j = 0; j<c;j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DFS(int y, int x, int count)
{
    if(y == 0 && x == c-1)
    {
        //cout<<"TT"<<endl;
        if(k == count)
        {
            ret++;
        }
        return;
    }

    //Print();

    for(int i =0;i<4;i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;
        if(arr[ny][nx] == 'T' || visited[ny][nx] != 0)
            continue;
        
        visited[ny][nx] = 1;
        DFS(ny, nx, count+1);
        visited[ny][nx] = 0;
    }
}
int main()
{
    cin>>r>>c>>k;

    for(int i =0; i < r;i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin>>arr[i][j];
        }
    }

    visited[r-1][0] = 1;
    DFS(r-1,0, 1);

    cout<<ret;
}