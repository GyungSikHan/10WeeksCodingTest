#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int>a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}
int main()
{
    cin>>n;
    v.resize(n,{});
    for(int i = 0; i<n; i++)
    {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    priority_queue<int,vector<int>, greater<int>> pq;
    int day= 1;

    for(int i = 0; i < v.size(); i++)
    {
        pq.push(v[i].second);
        if(v[i].first <pq.size())
        {
            //cout<<pq.top()<<endl;
            pq.pop();
        }
    }

    int ret{};
    while(pq.empty() == false)
    {
        //cout<<pq.top()<<endl;
        ret += pq.top();
        pq.pop();
    }
    cout<<ret;
}