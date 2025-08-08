//https://www.acmicpc.net/problem/2852 v
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,t,team1,team2,sum1,sum2;
string s,Prev;

int ChangeInt(string data)
{
	return stoi(data.substr(0, 2)) * 60 + stoi(data.substr(3, 2));
}

void Solution(int& sum, string data)
{
	sum += ChangeInt(data) - ChangeInt(Prev);
}

string ChangeString(int data)
{
	string hour = "00" + std::to_string(data / 60);
	string se = "00" + std::to_string(data % 60);

	return hour.substr(hour.size()-2,2) + ":" + se.substr(se.size()-2,2);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t >> s;
		if (team1 > team2)
			Solution(sum1,s);
		else if (team1 < team2)
			Solution(sum2,s);
		t == 1 ? team1++ : team2++;
		Prev = s;
	}

	if (team1 > team2)
		Solution(sum1,"48:00");
	else if (team1 < team2)
		Solution(sum2,"48:00");

	cout << ChangeString(sum1) << endl;
	cout << ChangeString(sum2) << endl;
}

//왜자꾸 틀리는지 반례를 못찾겠음....ㅠ