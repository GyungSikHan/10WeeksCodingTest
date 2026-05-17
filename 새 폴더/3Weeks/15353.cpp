#include <bits/stdc++.h>

using namespace std;

string s, s2;
int len;
int main()
{
    cin >> s >> s2;
    len = max(s.size(), s2.size());

    string temp{};
    int data{};
    reverse(s.begin(), s.end());
    reverse(s2.begin(), s2.end());
   
    for(int i = 0; i<len;i++)
    {
        int a{};
        int b{};
        if(s.size() > i)
            a = s[i] - '0';
        if(s2.size() > i)
            b = s2[i] - '0';
        data += a+b;

        temp += to_string(data%10);
        data /= 10;
    }
    if(data != 0)
        temp+=to_string(data);
    reverse(temp.begin(), temp.end());

    cout << temp;
}
