#include<bits/stdc++.h>

using namespace std;

string s;
int arr[30];

int main()
{
    cin>>s;

    for(int i = 0; i < s.size(); i++)
        arr[s[i] - 'a']++;

    for(int i = 0; i <= 'z' - 'a'; i++)
        cout<<arr[i]<<" ";
}