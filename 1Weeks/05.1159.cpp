//https://www.acmicpc.net/problem/1159
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n{};
    cin>>n;
    vector<int> v(26,0);
    for (int i = 0; i < n; i++) 
    {
        string s{};
        cin>>s;

        v[s.at(0) - 'a']++;
    }

    bool b{};
    for (int i = 0; i < 26; i++) 
    {
        if(v[i] >= 5)
        {
            b = true;
            char c = 'a'+i;
            cout<<c;
        }
    }

    if(b == false)
        cout<<"PREDAJA"<<endl;

}