//x
#include<bits/stdc++.h>

using namespace std;
struct SCV
{
    int a, b, c;
};
int attack[6][3]
{
    {9,3,1}, {9,1,3},
    {3,9,1}, {3,1,9},
    {1,9,3}, {1,3,9}
};

int n;
int scv[3];
int arr[61][61][61];
int ret = 987654321;

void Solution(int a, int b, int c)
{
    queue<SCV> qu;
    qu.push({a,b,c});

    arr[a][b][c] = 1;
    while(qu.empty() == false)
    {
        int ca = qu.front().a;
        int cb = qu.front().b;
        int cc = qu.front().c;
        qu.pop();
        if(ca == 0 && cb == 0 && cc == 0)
        {
            ret = arr[ca][cb][cc];
            break;
        }
        for(int i = 0; i < 6; i ++)
        {
            int na = ca-attack[i][0];
            int nb = cb-attack[i][1];
            int nc = cc - attack[i][2];
            if(na <=0)
                na = 0;
            if(nb <= 0)
                nb = 0;
            if(nc <= 0)
                nc = 0;
            if(arr[na][nb][nc] != 0)
                continue;
            arr[na][nb][nc] = arr[ca][cb][cc]+1;
            qu.push({na,nb,nc});
        }
    }
}

int main()
{
    cin>>n;
    for(int i = 0 ;i<n;i++)
    {
        cin>>scv[i];
    }
    
    arr[scv[0]][scv[1]][scv[2]] = 1;
    Solution(scv[0],scv[1],scv[2]);

    cout<<ret-1;
}