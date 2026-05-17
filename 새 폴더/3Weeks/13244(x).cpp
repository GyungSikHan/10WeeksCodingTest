#include<bits/stdc++.h>

using namespace std;

int t, n, m;

bool Check(const vector<int>& visited)
{
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
            return false;
    }
    return true;
}
bool DFS(const vector<vector<int>>& v, vector<int>& visited, int idx, int prv)
{
    bool b = true;
    for(int i = 1; i <= n; i++)
    {
        if(i == prv)
            continue;
        if(v[idx][i] == 1)
        {
            if(visited[i] == 0)
            {
                visited[idx] = 1;
                visited[i] = 1;
                b = DFS(v,visited, i, idx);
            }
            else
                return false;

            if(b == false)
                break;
        }
    }

    return b;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> v(n+1,vector<int>(n+1, 0));
        vector<int> visited(n+1, 0);
        
        bool er{};
        for(int i = 0; i<m; i++)
        {
            int a{}, b{};
            cin>>a>>b;
            if(v[a][b] == 1 || v[b][a] == 1)
                er = true;
            v[a][b] = 1;
            v[b][a] = 1;
        }
        if(er == true)
        {
            cout<<"graph\n";
            continue;
        }

        bool b = DFS(v,visited,1, 0);
        if(b == false)
        {
            cout<<"graph\n";
            continue;
        }
        b = Check(visited);
        if(b == false)
            cout<<"graph\n";
        else
            cout<<"tree\n";

    }
}