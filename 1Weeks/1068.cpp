#include<bits/stdc++.h>

using namespace std;
int n, a, d, root, ret;
vector<vector<int>> v;

int DFS(int x)
{
    int temp{};
    
    for(auto iter : v[x])
    {
        if( iter != d)
            temp += DFS(iter);
    }
    if(temp == 0)
    {
        return 1;
    }

    return temp;
}

int main()
{
    cin>>n;
    v.resize(n);
        for(int i = 0; i < n; i++)
    {
        cin>>a;
        if(a == -1)
            root = i;
        else
        {
            v[a].push_back(i);
        }
    }

    cin>>d;
    if(root != d )
        ret = DFS(root);
    cout<<ret;
}