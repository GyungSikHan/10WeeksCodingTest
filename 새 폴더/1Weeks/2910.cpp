//v
#include<bits/stdc++.h>

using namespace std;
int n,c;
map<int, int> m,m2;

bool compare(pair<int,int>a,pair<int, int>b)
{
    if(a.second == b.second)
    {
        // cout<<"a "<<a.first<<" "<<m2[a.first]<<"\n";
        // cout<<"b "<<b.first<<" "<<m2[b.first]<<"\n";
        // cout<<"ret "<<(m2[a.first] < m2[b.first])<<"\n";
        return m2[a.first] < m2[b.first];
    }
    return a.second > b.second;
}

int main()
{
    cin>>n>>c;
    for(int i = 0; i< n;i++)
    {
        int a{};
        cin>>a;
        m[a]++;
        if(m2[a] == 0)
        {
            m2[a] = i+1;
            //cout<<a<<" "<<i+1<<" "<<m[a]<<"\n";
        }
    }
    vector<pair<int, int>> v(m.begin(), m.end());

    // for (auto a : v)
    // {
    //     for (int i = 0; i < a.second; i++)
    //         cout << a.first << " ";
    // }
    // cout<<endl;

    sort(v.begin(), v.end(),compare);

    for(auto a : v)
    {
        for(int i = 0; i < a.second;i++)
            cout<<a.first<<" ";
    }
}