//https://www.acmicpc.net/problem/10808
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s{};
    cin>>s;
    vector<int> v(26, 0);

    for (int i = 0; i < s.size(); i++) 
    {
        v[s.at(i) - 'a']++;
    }

    for (int i = 0; i< 26; i++) 
    {
        cout<<v[i]<<" ";
    }
}