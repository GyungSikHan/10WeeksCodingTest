#include<bits/stdc++.h>

using namespace std;

int n;
string s, ret;
int arr[26];

int main()
{
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>s;
        arr[s[0] - 'a'] ++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(arr[i] >= 5)
            ret+=i+'a';
    }

    if(ret == "")
        cout<<"PREDAJA";
    else
        cout<<ret;
}
