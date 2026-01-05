#include<bits/stdc++.h>

using namespace std;

int n, s,e;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    cin>>n;
    v.resize(n,{0,0});
    for(int i = 0; i<n; i++)
    {
        cin>>s>>e;
        v[i] = {s,e};
    }

    sort(v.begin(), v.end(), compare);
    
    int start{}, end{}, ret{};
    for(auto iter : v)
    {
        if(iter.first >= end)
        {
            ret++;
            start = iter.first;
            end = iter.second;
        }
    }
    
    cout<<ret;
}

//end를 기준으로 정렬하여야 더 많은 경우를 담을 수 있음