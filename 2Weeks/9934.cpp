#include<bits/stdc++.h>

using namespace std;

int k;
vector<int> v;
vector<vector<int>>ret;
void Solution(int s, int e, int depth)
{
    if(depth == k)
        return;
    if(s>e)
        return;

    int mid = (s+e)/2;
    ret[depth].push_back(v[mid]);
    Solution(s,mid-1,depth+1);
    Solution(mid+1, e, depth+1);
}

int main()
{
    cin>>k;
    ret.resize(k);
    for(int i = 0; i < pow(2,k)-1; i++)
    {
        int a{};
        cin>>a;
        v.push_back(a);
    }
    int temp = k;
    Solution(0,v.size()-1,0);

    for(auto i : ret)
    {
        for(auto iter : i)
        {
            cout<<iter<<" ";
        }
        cout<<endl;
    }
}