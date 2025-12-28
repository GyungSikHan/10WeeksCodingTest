#include<bits/stdc++.h>

using namespace std;

int n,cnt, ret;
string s;
vector<int> v;

int Counts()
{
    int count{};
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((v[i] & (1<<j)) == 0)
                count++;
        }
    }

    return count;
}

int main()
{
    cin>>n;
    v.resize(n, 0);
    for(int i = 0; i<n; i++)
    {
        cin>>s;
        for(int j =0; j<s.size(); j++)
        {
            if(s[j] == 'H')
            {
                v[i] |= (1<<j);
            }
            else
                ret++;
        }
    }
    for(int i = 0; i<n; i++)
    {
        int temp{};
        for(int j = 0; j< n; j++)
        {
            v[0] = ~v[0];
        }            
        cout<<"I : "<<i<<endl;
        for(int j = 0; j< n; j++)
        {
            if((v[i] & (1<<j)) == 0 )
            {
                cout<<(1<<j)<<endl;
                temp++;
            }            
        }
        cout<<endl;

        ret = min(ret, temp);
    }

    cout<<ret;
}