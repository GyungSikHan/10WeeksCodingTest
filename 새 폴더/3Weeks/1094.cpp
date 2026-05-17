#include<bits/stdc++.h>

using namespace std;
const int len = 64;

int x, ret;
vector<int>v;

int Sum()
{
    if(v.empty() == true)
        return 0;
    
    int sum{};
    for(int i = 0; i < v.size(); i++)
    {
        sum+=v[i];
    }
    return sum;
}
int main()
{
    cin>>x;
    if(len == x)
    {
        cout<<1;
        return 0;
    }
    ret = len;
    while(ret != x && ret > 0)
    {
        ret = ret / 2;
        //cout<<ret<<endl;
        int sum = Sum() + ret;
        if(sum > x)
            continue;
        
        v.push_back(ret);
        
        if(sum == x)
        {
            break;
        }
    }

    cout<<v.size();
}