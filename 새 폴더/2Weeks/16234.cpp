#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1},dx[4]{-1,0,1,0};
int n,r,c,ret;
int arr[51][51];
int visited[51][51];

void print()
{
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }
}

void DFS(int y, int x, vector<pair<int,int>>& temp)
{
    for(int i = 0; i<4; i++)
    {
        int ny = dy[i]+y;
        int nx = dx[i]+x;

        if(ny<0||ny>=n||nx<0||nx>=n)
            continue;
        if(visited[ny][nx] == 1)
            continue;
        int sub = abs(arr[ny][nx] - arr[y][x]);
        if(r<=sub && sub <= c)
        {
            temp.push_back({ny,nx});
            visited[ny][nx] = 1;
            DFS(ny,nx, temp);
        }
    }
}

int main()
{
    cin>>n>>r>>c;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }

    while(true)
    {
        memset(visited, 0, sizeof(visited));
        bool b{};
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(visited[i][j] != 1)
                {
                    vector<pair<int,int>>temp;
                    temp.push_back({i,j});
                    visited[i][j] = 1;
                    DFS(i,j, temp);
                    if(temp.size() > 1)
                    {
                        // cout<<"temp"<<endl;
                        b = true;
                        int dev{};
                        for(auto iter : temp)
                            dev += arr[iter.first][iter.second];

                        dev /= temp.size();
                        for(auto iter : temp)
                            arr[iter.first][iter.second] = dev;
                    }
                }
            }
        }
        // cout<<endl;
        // print();

        if(b == false)
            break;
        ret++;
    }
    cout<<ret;
}