#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1},dx[4]{-1,0,1,0};

int r,c, ret;
vector<pair<int, int>>F;
pair<int, int> J;
char v[1001][1001];
int fvisited[1001][1001];
int jvisited[1001][1001];

void print(int a[1001][1001])
{
    cout<<endl;
    for(int i = 0; i < r; i++)
    {
        for(int j= 0; j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void fBFS()
{
    queue<pair<int, int>> qu;
    for(auto iter : F)
    {
        qu.push(iter);
        fvisited[iter.first][iter.second] = 1;
    }

    while (qu.empty() == false)
    {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            if(v[ny][nx] == '#')
                continue;
            if(fvisited[ny][nx] != 0)
                continue;
            fvisited[ny][nx] = fvisited[y][x]+1;
            qu.push({ny,nx});
        }
        //print(fvisited);
    }
}

bool jBFS()
{
    bool ex{};
    queue<pair<int, int>>qu;
    qu.push(J);
    jvisited[J.first][J.second] = 1;
    while(qu.empty() == false)
    {
        bool b{};
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();

        //cout<<y<<" "<<x<<endl;
        if((y == 0 &&(x >= 0 && x < c)) || (y == r - 1 &&(x >= 0 && x < c)) || (x == 0 && ( y >= 0 && y < r)) || (x == c-1 &&( y >= 0 && y < r)))
        {
            ret = jvisited[y][x];
            ex = true;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0||ny>=r||nx<0||nx>=c)
                continue;
            if(v[ny][nx] == '#')
                continue;
            if(fvisited[ny][nx] != 0 &&fvisited[ny][nx] <= jvisited[y][x] + 1)
                continue;
            if(jvisited[ny][nx] != 0)
                continue;
            b = true;
            jvisited[ny][nx] = jvisited[y][x] + 1;
            qu.push({ny,nx});
        }
        // cout<<"j"<<endl;
        // print(jvisited);   
    }
    return ex;
}

int main()
{
    
    cin>>r>>c;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin>>v[i][j];
            if(v[i][j] == 'F')
                F.push_back({i,j});
            if(v[i][j] == 'J')
                J = make_pair(i,j);
        }
    }

    fBFS();
    bool ex = jBFS();

    if(ex == 0)
        cout<<"IMPOSSIBLE";
    else
        cout<<ret;

}