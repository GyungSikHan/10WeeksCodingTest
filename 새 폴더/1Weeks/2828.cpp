#include<bits/stdc++.h>

using namespace std;

int n,m,j;
vector<int>arr;
int s=1,e,ret = 0;

int main()
{
    cin>>n>>m;
    cin>>j;
    
    for(int i = 0; i < j; i++)
    {
        int a{};
        cin>>a;
        arr.push_back(a);
    }

    e = m;
    for(int i = 0; i < j; i++)
    {
        if(s > arr[i])
        {
            ret += s-arr[i];
            e -= s-arr[i];
            s = arr[i];
        }
        else if(e < arr[i])
        {
            ret += arr[i] - e;
            s += arr[i] - e;
            e = arr[i];
        }
        //cout << s << " : "  << e << "\n";
    }

    cout<<ret;
}