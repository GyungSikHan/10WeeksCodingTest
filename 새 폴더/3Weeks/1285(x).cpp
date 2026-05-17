#include<bits/stdc++.h>

using namespace std;

int n, ret = 987654321;
string s;
vector<int> v;

void go(int here)
{
    if(here == n+1)
    {
        int sum{};
        for(int i = 1; i <= (1<<(n-1)); i*=2)
        {
            int cnt{};
            for(int j = 1; j <= n; j++)
            {
                if(v[j] & i)
                    cnt++;
            }
            sum += min(cnt, n-cnt);
        }
        ret = min(ret, sum);
        return;
    }

    go(here+1);
    v[here] = ~v[here];
    go(here+1);
}

int main()
{
    cin>>n;
    v.resize(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        int value = 1;
        cin>>s;
        for(int j = 0; j <s.size(); j++)
        {
            if(s[j] == 'T')
                v[i] |= value;
            value *= 2;
        }
    }
    go(1);
    cout<<ret;
}
