#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
vector<vector<int>> visited;

int main()
{
    cin>>n;
    v.resize(n,vector<int>(n,0));
    visited.resize(n, vector<int>(n,0));
    
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            cin>>v[i][j];
        }
    }
    

}