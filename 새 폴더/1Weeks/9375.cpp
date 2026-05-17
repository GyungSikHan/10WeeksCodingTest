//V 경우의수 잘 생각해서 풀어보기
#include<bits/stdc++.h>

using namespace std;

int t,k,ret;
string s, s2;


int Solve(map<string, int>ma)
{
    int temp= 1;
    for(auto a : ma)
    {
        temp *= (a.second+1);
    }

    return temp-1;
}


int main()
{
    cin>>t;
    for(int i =0;i<t; i++)
    {
        map<string, int>ma;
        cin>>k;
        for(int j = 0; j < k;j++)
        {
            cin>>s>>s2;

            if(ma.empty() == true)
            {
                ma[s2] = 1;
            }
            else if(ma.find(s2) == ma.end())
            {
                ma[s2] = 1;
            }
            else    
            {
                ma[s2] += 1;
            }
        }
        ret = Solve(ma);
        cout<<ret<<endl;

    }
}