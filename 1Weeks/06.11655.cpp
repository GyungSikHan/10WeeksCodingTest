//https://www.acmicpc.net/problem/11655
#include <cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string s{};
    string ret{};
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) 
    {
        if( 'a'<=s.at(i) && s.at(i) <= 'z')
        {
            char c = s.at(i) + 13;
            if(s.at(i) + 13 > 'z')
            {
                c = 'a' + c-'z'-1;
            }

            ret += c;
        }
        else if( 'A'<=s.at(i) && s.at(i) <= 'Z')
        {
            char c = s.at(i) + 13;
            if(s.at(i) + 13 > 'Z')
            {
                c = 'A' + c-'Z'-1;
            }

            ret += c;
        }
        else
            ret+= s.at(i);
    }

    cout<<ret<<endl;
}
