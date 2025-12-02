#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

string s;
int length;

int main()
{
    cin>>s;
    length = s.size()/2;

    string temp1{}, temp2{};

    temp1 = s.substr(0, length);
    if(s.size() % 2 == 0)
        temp2 = s.substr(length);
    else
        temp2 = s.substr(length+1);
    
    reverse(temp2.begin(), temp2.end());
    
    if(temp1 == temp2)
        cout<<1;
    else
        cout<<0;
}