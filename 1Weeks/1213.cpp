#include <bits/stdc++.h>

using namespace std;

string s;
int arr[26];
string temp{};

void Solve()
{
    int b{};
    for (int i = 25; i >= 0; i--)
    {
        string c{};
        if (arr[i] == 0)
            continue;
        if(arr[i] %2 == 1)
            b++;
        if(b > 1)
            break;
        while(arr[i] != 0)
        {
            c = 'A' + i;
            if (arr[i] % 2 == 0)
            {
                temp = c + temp;
                temp += c;
                arr[i] -= 2;
            }
            else
            {
                temp.insert(temp.size() / 2, c);
                arr[i]--;
            }
        }
    }
    if(b > 1)
        cout<<"I'm Sorry Hansoo";
    else
        cout << temp;
}

int main()
{
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        arr[(s[i] - 'A')]++;

    Solve();
}