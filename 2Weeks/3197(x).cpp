#include<bits/stdc++.h>

using namespace std;

const int Max = 1501;
int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};

int r,c,day;
char arr[Max][Max];
int visited[Max][Max], visitedSwan[Max][Max];
//int swanY, swanX, y, x;
string s;
queue<pair<int, int>> swanQ, waterQ, tempSwanQ, tempWaterQ;

pair<int, int> swan;

void Clear(queue<pair<int, int>>& qu)
{
    queue<pair<int, int>> temp;
    swap(qu, temp);
}

bool MoveSwan()
{
    while(swanQ.empty() == false)
    {
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i]+y;
            int nx = dx[i]+x;
            if(ny<0||r<= ny || nx < 0 || c <= nx)
                continue;
            if(visitedSwan[ny][nx] == 1)
                continue;
            visitedSwan[ny][nx] = 1;
            if(arr[ny][nx] == '.') 
                swanQ.push({ny,nx});
            else if(arr[ny][nx] == 'X') 
                tempSwanQ.push({ny,nx});
            else if(arr[ny][nx] == 'L')
                return true;
        }
    }
    return false;
}

void BrokenWater()
{
    while(waterQ.size() != 0)
    {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();

        for(int i = 0; i<4; i++)
        {
            int ny = dy[i]+y;
            int nx = dx[i]+x;
            if(ny<0|| r <= ny || nx < 0 || c <= nx)
                continue;
            if(visited[ny][nx] == 1)
                continue;
            if(arr[ny][nx] == 'X')
            {
                visited[ny][nx] = 1;
                tempWaterQ.push({ny,nx});
                arr[ny][nx] = '.';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>r>>c;

    for(int i = 0; i < r;i++)
    {
        cin>>s;
        for(int j = 0; j < c; j++)
        {
            arr[i][j] = s[j];
            if(arr[i][j] == 'L')
            {
                swan = make_pair(i, j);
            }
            if(arr[i][j] == '.' || arr[i][j] == 'L')
            {
                visited[i][j] = 1;
                waterQ.push({i,j});
            }
        }
    }
    swanQ.push(swan);
    visitedSwan[swan.first][swan.second] = 1;
    
    while(MoveSwan() == false)
    {
        day++;
        BrokenWater();
        waterQ = tempWaterQ;
        swanQ = tempSwanQ;
        Clear(tempSwanQ);
        Clear(tempWaterQ);
    }

    cout<<day;
}