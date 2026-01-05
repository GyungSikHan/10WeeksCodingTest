#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int,int>b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main()
{
    cin>>n;
    v.resize(n, pair<int,int>({0,0}));
    for(int i = 0; i < n; i++)
    {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    int sum{};
    for(int i = 0; i < n; i++)
    {
        if(sum == 0)
        {
            sum = v[i].first+v[i].second;
            //e = v[i].second;
        }
        else
        {
            if(sum == v[i].first)
            {
                sum += v[i].second;
                //e = v[i].second;
                //cout<<"sum == first " <<sum<<endl;                
            }
            else
            {
                if(v[i].first < sum)
                {
                    sum += v[i].second;
                    //cout<<"sum > first " <<sum<<endl;                
                }
                else
                {
                    sum = v[i].first+v[i].second;
                    //cout<<"sum < first "<<sum<<endl;
                }
            }
        }
    }   

    cout<<sum;
}