#include<bits/stdc++.h>

using namespace std;

int n;
int t = 3, d = 2, m = -1;
vector<int> v,v2;
int ret = 987654321;

void go(int data, int cnt)
{
    if(data < 1 || ret < cnt)
        return;

    if(data == 1)
    {
        if(ret > cnt)
        {
            ret = cnt;
            v2 = v;
        }
        return;
    }
    v.push_back(data);
    if(data % 3 == 0)
        go(data/3, cnt+1);
    if(data % 2 == 0)
        go(data/2, cnt + 1);
    if(data - 1 != 0)
        go(data - 1, cnt+1);
    v.pop_back();
}
int main()
{
    cin>>n;
    go(n, 0);
    v2.push_back(1);
    cout<<ret<<"\n";
    for(auto iter : v2)
        cout<<iter<<" ";
}