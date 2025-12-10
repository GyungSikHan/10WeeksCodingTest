#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> v;
vector<string>ret;

bool compare(string a, string b)
{
    //cout<<a<<" "<<b<<endl;
    if(a.size() == b.size())
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                return a[i] < b[i];
            }
        }
    }

    return a.size() < b.size();
}

void Solutuon(string temp)
{
    string stemp{};
    for(int i = 0; i < temp.size(); i++)
    {
        //cout<<"solutuon "<< temp[i]<<endl;
        if(temp[i] >= '0' && temp[i] <= '9')
        {
            if(stemp.size() != 0 && stemp[0] == '0')
                stemp = temp[i];
            else
                stemp+=temp[i];
            //cout<<"1 "<<stemp<<endl;
        }
        else
        {
            if(stemp != "")
            {
                //cout<<"0 "<<stemp<<endl;
                if(stemp.size() != 1 && stemp[0] == '0')
                {
                    stemp = stemp.substr(stemp[0]+1);
                    //cout<<stemp<<endl;
                }
                
                ret.push_back(stemp);
            }
            stemp = "";
        }
    }
    if(stemp != "")
        ret.push_back(stemp);
}

int main()
{
    cin>>n;

    for(int i = 0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }

    for(string iter : v)
    {
        Solutuon(iter);
    }
    sort(ret.begin(), ret.end(), compare);
    //cout<<endl;
    for(string i : ret)
        cout<<i<<"\n";
}
