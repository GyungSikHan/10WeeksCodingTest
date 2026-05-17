#include <bits/stdc++.h>

using namespace std;

int n,m, lo = 1, he, ret;
vector<int> v;

bool Solution(int mid)
{
    int temp = mid;
    int cnt = 1;
    for(auto iter : v)
    {
        //cout<<temp <<" - "<<iter<<endl;
        if(mid - iter < 0)
        {
            mid = temp;
            cnt++;
        }
        mid -= iter;
        //cout<<temp<<" "<<cnt<<endl;
    }
    
    //cout<<"CNT"<<cnt<<endl;
    return cnt <= m;
}

int main()
{
    cin>>n>>m;
    v.resize(n,0);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
        he+= v[i];
        lo = max(lo, v[i]);
    }

    while(lo <= he)
    {
        int mid = (lo+he)/2;
       //cout<<"mid "<<mid<<endl<<endl;
        if(Solution(mid))
        {
            //cout<<"TRUE"<<endl<<endl;
            ret = mid;
            he = mid-1;
        }
        else
        {
            //cout<<"FALSE"<<endl<<endl;
            lo = mid+1;
        }
    }

    cout<<ret;
}