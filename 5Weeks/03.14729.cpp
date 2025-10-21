//https://www.acmicpc.net/problem/14729
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n;
float score;
priority_queue<float,vector<float>, greater<float>> q;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score;
		q.push(score);
	}

	for (int i = 0; i < 7; i++)
	{
		cout << fixed << setprecision(3);
		cout << q.top() << "\n";
		q.pop();
	}
}