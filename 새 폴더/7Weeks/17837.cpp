#include<bits/stdc++.h>

using namespace std;
int dx[4]{1,-1,0,0};
int dy[4]{0,0,-1,1};
int INF = 987654321;
int cnt; 
struct point
{
    int y, x, dir, i;
};

int n, k, y, x, dir;
int m[13][13];
vector<int> v[13][13];
vector<point> v2;

bool isOver()
{
    for(auto iter : v2)
    {
        cout << iter.y << " : " << iter.x << "\n";
        if(v[iter.y][iter.x].size() >= 4)
            return true;
    }

    return false;
}

void move(int y, int x, int dir, int idx)
{
    int ny = y+dy[dir];
    int nx = x+dx[dir];
    
    vector<int> list;
    auto temp = find(v[y][x].begin(), v[y][x].end(), idx);    
    for(; temp != v[y][x].end(); temp++)
    {
        list.push_back(*temp);
    }
    if(m[ny][nx] == 1)
    {
        reverse(list.begin(), list.end());
    }
    else if(ny<0||ny>=n||nx<0||nx>=n || m[ny][nx] == 2)
    {
        dir ^= 1;
        ny = y+dy[dir];
        nx = x + dx[dir];
        if(ny<0||ny>=n||nx<0||nx>=n || m[ny][nx] == 2)
        {
            return;
        }   
    }
    for(auto i : list)
        v[ny][nx].push_back(i);
    bool flag{};
    for(auto iter : list)
    {
        v2[iter].y = ny;
        v2[iter].x = nx;
        v2[iter].dir = dir;
    }
    v[y][x].erase(temp, v[y][x].end());

}

bool simul()
{
    for(auto i : v2)
    {
        move(i.y, i.x, i.dir, i.i); 
        if(isOver())
            return true;
    }
    return false;
}

void go()
{
    while(true)
    { 
        if(++cnt >= 1000)
        { 
            break;
        }
        if(simul() == true)
            break;
    }
}

int main()
{
    cin>>n>>k;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>m[i][j];
        }
    }

    for(int i = 0; i < k; i++)
    {
        cin>>y>>x>>dir;
        y--;
        x--;
        dir--;
        v[y][x].push_back(i);
        v2.push_back({y,x, dir, i});
    } 
    go();
    if(cnt >= 1000) cout << -1 << '\n';
    else cout << cnt << '\n';

}