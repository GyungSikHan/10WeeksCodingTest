#include<bits/stdc++.h>

using namespace std;

int n, k, ret;
vector<string> vs;
string s, temp = "antatica";
int c[30];



void go(int count, int idx)
{
    //cout<<idx<<endl;
    if(idx == 26)
    {
        //cout<<"test"<<endl;
        int cnt{};
        for(auto iter : vs)
        {
            int a{};
            for(auto child : iter)
            {
                if(c[child-'a'] == 1)
                {
                    //cout<<child<<endl;
                    a++;
                }
            }
            if(a == iter.size())
            {
                //cout<<"size: "<<a<<endl;
                cnt++;
            }
            //cout<<endl<<endl;
        }
        ret = max(ret, cnt);
        return;
    } 
    if(c[idx] == 1)
        go(count, idx+1);
    else
    {
        if(count - 1 >= 0)
        {
            c[idx] = 1;
            go(count-1, idx + 1);
        }
        c[idx] = 0; 
        go(count, idx + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    int count{};
    for(char i : temp)
    {
        if(c[i - 'a'] == 0)
        {
            count++;
            c[i - 'a'] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        vs.push_back(s);
    }
    //cout<<k-count<<endl;
    if(k - count >=0)
        go(k - count, 0);
    cout<<ret;
}

