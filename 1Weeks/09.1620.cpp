//https://www.acmicpc.net/problem/1620 V
#include<iostream>
#include<map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n{}, m{};
    cin >> n >> m;

    map<int, string> po{};
    map<string, int> po2{};

    for (int i = 0; i < n; i++)
    {
        string s{};
        cin >> s;

        po.insert({ i,s });
        po2.insert({ s,i + 1 });
    }

    for (int i = 0; i < m; i++)
    {
        string s{};
        cin >> s;


    	if (s.at(0) < 'A' || s.at(0) > 'Z')
            cout << po[stoi(s) - 1] << "\n";
        else
            cout << po2[s] << "\n";
    }
}

//ios_base::sync_with_stdio(false);
//cin.tie(nullptr);
//cout.tie(nullptr);
//이거 왜워서 쓰기