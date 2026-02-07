#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v,v2;

int Solution(const vector<int> a, const vector<int>b)
{
    size_t idx{},idx2{};
    int cnt = a.size();
    while(idx < a.size() && idx2 < b.size())
    {
        //cout<<a[idx] <<" "<<b[idx2]<<endl;
        if(a[idx] == b[idx2])
        {
            cnt--;
            idx++;
            idx2++;
        }
        else if(a[idx] < b[idx2])
        {
            idx++;
        }
        else    
            idx2++;
    }
    //cout<<cnt<<endl<<endl;
    if(cnt < 0)
        cnt = 0;
    return cnt;
}

int main()
{
    cin>>n>>m;
    v.resize(n,0);
    v2.resize(m,0);

    for(int i = 0; i < n; i++)
        cin>>v[i];
    for(int i = 0; i < m; i++)
        cin>>v2[i];

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    int ret = Solution(v,v2);
    ret += Solution(v2,v);
    cout<<ret<<"\n";
}