#include<bits/stdc++.h>
#include <string>

using namespace std;

int n;
int temp = 666;
string s;

int main()
{
    cin>>n;
    if(n == 1)
    {
        cout<<temp<<endl;
        return 0;
    }
    n -=1;
    while(n != 0)
    {
        temp++;
        s = to_string(temp);
        if(s.find("666") != string::npos)
            n--;
    }
    cout<<s<<"\n";
}