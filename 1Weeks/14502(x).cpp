#include<bits/stdc++.h>

using namespace std;

int dx[4] {-1,0,1,0};
int dy[4] {0,-1,0,1};
int n,m, ret;
int arr[8][8];
int temp[8][8];

void make(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = dx[i]+x;
        int ny = dy[i] +y;

        if(nx<0|| nx>=n||ny<0||ny>=m)
            continue;
        if(temp[nx][ny] == 0)
        {
            temp[nx][ny] = 2;
            make(nx,ny);
        }
    }
}

int countBio()
{
    int cou{};
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            if(temp[i][j] == 0)
                cou++;
        }
    }

    return cou;
}

int Bio()
{
    memcpy(temp, arr, sizeof(arr));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(temp[i][j] == 2)
            {
                make(i,j);
            }
        }
    }

    return countBio();
}

void Solve(int count)
{
    if(count == 3)
    {
        ret = max(ret, Bio());
        return;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 0)
                {
                    arr[i][j] = 1;
                    Solve(count+1);
                    arr[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    Solve(0);
    cout<<ret;
}
