//https://www.acmicpc.net/problem/9996  V
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n{};
    string s{};

    cin>>n;
    cin>>s;
    int pos = s.find('*');
    vector<string> v;
    v.push_back(s.substr(0,pos));
    v.push_back(s.substr(pos+1));

    for (int i = 0; i < n; i++) 
    {
        string temp{};
        cin>>temp;

        if(v[0].size() + v[1].size() > temp.size())
            cout<<"NE"<<endl;
        else
        {
            if(v[0] == temp.substr(0,v[0].size()) && v[1] == temp.substr(temp.size() - v[1].size()))
               cout<<"DA"<<endl;
            else
                cout<<"NE"<<endl;
        }
    }
}
