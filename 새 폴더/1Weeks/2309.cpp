#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> v2;
int sum;
int ret;

int main()
{
    for(int i = 0;i<9;i++)
    {
        int a{};
        cin>>a;
        v.push_back(a);
        sum+=a;
    }

    sort(v.begin(), v.end());
    bool b{};
    for(int i = 0; i < 9; i++)
    {
        b = false;
        sum-=v[i];
        for(int j = 0; j < 9; j++)
        {
            sum -=v[j];
            if(sum == 100)
            {
                b = true;
                v2.push_back(i);
                v2.push_back(j);
                break;
            }
            sum += v[j];
        }
        if(b == true)
            break;
        sum += v[i];
    }

    for(auto i : v)
    {
        if(i == v[v2[0]] || i == v[v2[1]])
            continue;
        cout<<i<<"\n";
    }
    
}
