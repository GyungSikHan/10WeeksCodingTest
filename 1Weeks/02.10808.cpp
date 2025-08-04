//https://www.acmicpc.net/status?user_id=gksrudtlr3&problem_id=10808&from_mine=1
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