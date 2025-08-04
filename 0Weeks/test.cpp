#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v{};
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        v.push_back(i);
    }

    auto it = unique(v.begin(),v.end());
    cout<<it - v.begin()<<endl;

    for(int i = 0; i < it-v.begin(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}