#include<bits/stdc++.h>

using namespace std;

int n,m, lo = 1,hi, ret = 987654321;
vector<int> v;

bool Solution(int mid)
{
    int blue = 1;
    int temp{};
    for(int i =0 ; i < v.size(); i++)
    {
        temp += v[i];
        //cout<<temp<<endl;

        if(v[i] > mid)
            return false;

        if(temp > mid)
        {
            //cout<<"false"<<endl<<endl;
            blue++;
            temp = 0;
            temp = v[i];
            //cout<<temp<<endl;
        }

    }

    if(blue <= m)
        return true;

    return false;
}

int main()
{
    cin>>n>>m;
    v.resize(n,0);
    for(int i =0; i < n; i++)
    {
        cin>>v[i];
    }

    for(int i : v)
        hi += i;

    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        //cout<<"MID"<<mid<<endl<<endl;

        if(Solution(mid))
        {
            //cout<<"TRUE"<<endl<<endl;
            ret = mid;
            hi = mid - 1;
        }
        else
        {
            //cout<<"FALSE"<<endl;

            lo = mid+1;
        }
    }

    cout<<ret;
    
}