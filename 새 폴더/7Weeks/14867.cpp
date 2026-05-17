
#include<bits/stdc++.h>

using namespace std;

int a,b,c,d;
map<pair<int, int>, int> m;
queue<pair<int, int>> qu;

void enque(int x, int y, int d)
{
    if(m[{x,y}])
        return;
    m[{x,y}] = d+1;
    qu.push({x,y});
}
int bfs(int x, int y)
{
    m[{x,y}] = 1;
    qu.push({x,y});

    while(qu.empty() == false)
    {
        x = qu.front().first;
        y = qu.front().second;
        qu.pop();
        
        enque(a, y, m[{x,y}]);
        enque(x,b,m[{x,y}]);
        enque(0, y, m[{x,y}]);
        enque(x, 0, m[{x,y}]);
        enque(min(x+y, a), max(0, x+y-a), m[{x,y}]);
        enque(max(0, x+y-b), min(x+y, b), m[{x,y}]);
    }
    if(m[{c,d}])
        return m[{c,d}]-1;
    else
        return -1;
}


int main()
{
    cin>>a>>b>>c>>d;
   cout<<bfs(0,0);
}
