#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int r, c, cnt;
vector<vector<char>> arr;
vector<vector<int>> visited;
vector<pair<int, int>> swan;

void Print()
{
    cout<<endl;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Print2()
{
    cout<<endl;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool Meet(vector<vector<int>> temp)
{
    queue<pair<int,int>> qu;
    qu.push({swan[0].first, swan[0].second});
    temp[swan[0].first][swan[0].second] = 1;
    
    while(qu.empty() == false)
    {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();

        if(y == swan[1].first && x == swan[1].second)
        {
            return true;
        }

        for(int i = 0;i<4;i++)
        {
            int ny = dy[i]+y;
            int nx=dx[i]+x;

            if(ny<0 || r <=ny || nx < 0|| c <= nx)
                continue;
            if(temp[ny][nx] == 1)
                continue;
            if(arr[ny][nx] == 'X')
                continue;
            qu.push({ny,nx});
            temp[ny][nx] = 1;
        }
    }

    return false;
}

void IceBroken(int i, int j)
{
    queue<pair<int,int>> qu;
    qu.push({i,j});
    visited[i][j] = 1;

    while(qu.empty() == false)
    {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();

        for(int i = 0;i<4;i++)
        {
            int ny = dy[i]+y;
            int nx=dx[i]+x;

            if(ny<0 || r <=ny || nx < 0|| c <= nx)
                continue;
            if(visited[ny][nx] == 1)
                continue;
            if(arr[ny][nx] == 'X')
            {
                visited[ny][nx] = 1;
                arr[ny][nx] = '.';
                continue;
            }
            qu.push({ny,nx});
            visited[ny][nx] = 1;
        }

        //Print();
        
    }
}


int main()
{
    cin>>r>>c;
    arr.resize(r, vector<char>(c,'\0'));
    visited.resize(r,vector<int>(c, 0));
    for(int i = 0;i<r;i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'L')
            {
                swan.push_back({i,j});
            }
        }
    }

    while(Meet(visited) == false)
    {
        cnt++;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j< c;j++)
            {
                if(arr[i][j] != 'X' && visited[i][j] == 0)
                {
                    IceBroken(i,j);
                }
            }
        }

        //Print2();

        for(auto& iter : visited)
        {
            fill(iter.begin(), iter.end(), 0);
        }
    }

    cout<<cnt;

}