#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> people;
vector<int> visited;
vector<vector<int>> let;

int sum()
{
    int sum{};
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
            sum += people[i];
    }

    return sum;
}

void DFS(int idx, int sum)
{
    i6
}

int main()
{
    cin>>n;
    people.resize(n+1,0);
    let.resize(n+1);
    visited.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin>>people[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int a{};
        cin>>a;
        for(int j = 0; j < a; j++)
        {
            int b{};
            cin>>b;
            let[i].push_back(b);
        }
    }

}