#include<bits/stdc++.h>

using namespace std;

int n,m, a,b, cnt;
vector<vector<int>>v;
vector<int> visited;
vector<int> ret;

void Check(int x, int& count)
{
    visited[x] = 1;

    for(auto iter : v[x])
    {
        //cout<<"check"<<iter<<endl;
        if(visited[iter] == 0)
        {
            count++;
            Check(iter, count);
        }
    }
}

int main()
{
    cin>>n>>m;

    v.resize(n+1);
    visited.resize(n+1);
    for(int i = 0; i<m;i++)
    {
        cin>>a>>b;
        v[b].push_back(a);
    }
    
    for(int i = 1; i<=n;i++)
    {
        fill(visited.begin(), visited.end(), 0);
        int temp = 1;
        Check(i, temp);
        //cout<<"i " <<i<<" temp "<<temp<<endl;
        if(temp > cnt)
        {
            cnt = temp;
            ret.erase(ret.begin(), ret.end());
            
            ret.push_back(i);
        }
        else if(temp == cnt)
        {
            ret.push_back(i);
        }
    }

    sort(ret.begin(), ret.end());

    for(auto iter : ret)
        cout<<iter<<" ";
}