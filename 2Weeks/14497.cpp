#include<bits/stdc++.h>

using namespace std;

int dy[4]{0,-1,0,1}, dx[4]{-1,0,1,0};
int n,m, a,b;
int by, bx,jy,jx, ret = 1;
char arr[301][301];
int visited[301][301];

void print()
{
    cout<<endl;
    for(int i = 1; i <=n;i++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Check()
{
    queue<pair<int, int>> qu;
    qu.push({jy,jx});
    visited[jy][jx] = 1;
    bool b = false;
    while (qu.empty() == false)
    {
        int curry = qu.front().first;
        int currx = qu.front().second;
        qu.pop();

        if(curry == by && currx == bx)
        {
            b = true;
            break;
        }
        for(int i =0;i<4;i++)
        {
            int ny = curry + dy[i];
            int nx = currx + dx[i];
            //cout<<"curr "<<ny<<" "<<nx<<endl;
            if(ny < 1 || ny > n || nx < 1 || nx > m)
                continue;
            if(visited[ny][nx] == 1)
                continue;
            if(arr[ny][nx] == '1')
            {
                //cout<<"flase"<<ny<<" "<<nx;
                arr[ny][nx] = '0';
            }
            else if(arr[ny][nx] == '#')
            {
                b = true;
                break;
            }
            else
            {
                //cout<<"push"<<endl;
                qu.push({ny,nx});
            }
            visited[ny][nx] = 1;
            //print();
        } 

       //print();

        if(b == true)
        {
            break;
        }
    }

    return b;
}


int main()
{
    cin>>n>>m;
    cin>>jy>>jx>>by>>bx;
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>> arr[i][j];
        }
    }
    //print();
    //int temp{};
    while (Check() == false)
    {
        ret++;
        memset(visited, 0, sizeof(visited));
        //cout<<"te"<<endl;
        // temp++;
        // if(temp == 2)
        //     break;
        
    }
    
    cout<<ret;
}