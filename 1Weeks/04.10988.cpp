//https://www.acmicpc.net/problem/10988
#include <iostream>
#include<vector>

using namespace std;

int main()
{
    string s{};
    cin>>s;

    int half = s.size()/2;
    vector<char> v;
    vector<char> v2;


    for (int i = 0; i < half; i++) 
    {
        v.push_back(s.at(i));
    }
    for (int i = s.size()-1; i>=half; i--) 
    {
        v2.push_back(s.at(i));
    }

    bool b{};
    for (int i = 0; i < half; i++) 
    {
        if(v[i] != v2[i])
        {
            b = true;
            break;
        }
    }

    if(b == false)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}
